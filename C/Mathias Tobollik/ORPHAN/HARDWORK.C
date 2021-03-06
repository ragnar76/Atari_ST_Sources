/********************************************************************/
/* HARDWORK.C														*/
/********************************************************************/
/* ORPHAN	- verwaiste Cluster finden								*/
/*																	*/
/* (C)1991 Mathias Tobollik	f�r das TOS-Magazin						*/
/*																	*/
/********************************************************************/
/* In diesem Modul befinden sich die Routinen f�r das verfolgen von */
/* Dateien und Verzeichnissen und die Lade- und Speicherfunktionen. */
/********************************************************************/


/****************************************************************/
/* Includes:													*/
/****************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <ext.h>
#include <string.h>
#include <tos.h>
#include <hardwork.h>

void error( char *s );	/* (Die Fehlerfunktion aus ORPHAN.C) */



/****************************************************************/
/* FAT laden													*/
/****************************************************************/
void load_fat( int drive, BPB *p, INTELWD *fatbuf )
{
	/* Zur Sicherheit wird der Speicher erst mit Nullen gef�llt: */
	memset( (void *)fatbuf, 0, (size_t)(p->fsiz * p->recsiz) );
	
	/* Jetzt FAT Nr. 2 laden: */
	if( 0L != Rwabs( 0, (void *)fatbuf, p->fsiz, p->fatrec, drive ) )
		error( "[3][ Fehler beim lesen ! | Read - error ! ][ OK ]" );
}



/****************************************************************/
/* Neue FAT(s) schreiben										*/
/****************************************************************/
void save_fat( int drive, BPB *p, INTELWD *fatbuf )
{
	/* Zuerst Fat Nr 2:	*/
	if( 0L != Rwabs( 1, (void *)fatbuf, p->fsiz, p->fatrec, drive ) )
		error( "[3][ Fehler beim schreiben ! | Write - error ! ][ OK ]" );
	
	/* Dann FAT Nr. 1: */
	if( 0L != Rwabs( 1, (void *)fatbuf, p->fsiz, p->fatrec - p->fsiz, drive ) )
		error( "[3][ Fehler beim schreiben ! | Write - error ! ][ OK ]" );
}



/****************************************************************/
/* Verfolgen des Wurzelverzeichnisses							*/
/****************************************************************/
void trace_root( BPB *p, INTELWD *fat, DRIVE *d, int drive )
{
DIR *dir;					/* Das Directory im Speicher 		*/
int i, k;					/* Z�hler 							*/
unsigned int start;			/* der Startsektor des Directorys	*/
	
	/* Speicher f�r einen Cluster reservieren u. initialisieren: */
	
	if( NULL == (dir = (DIR *)malloc( (size_t)p->clsizb )) )
		error( "[3][ malloc() - Fehler ! | malloc() - error ! ][ OK ]" );	
	memset( (void *)dir, 0, (size_t)p->clsizb );
	
	/* Startsektor bestimmen: */
	start = p->fatrec + p->fsiz;
	
	/* Das Wurzelverzeichnis wird Clusterweise geladen und	*/
	/* ausgewertet. Man beachte, da� diese Routine auch mit	*/
	/* Clustergr��en != 1024 Bytes zurechtk�me.				*/
	for( k = 0; k < p->rdlen; k += p->clsiz )
	{		
		if( Rwabs( 0, (void *)dir, p->clsiz, start + k, drive ) )
			error( "[3][ Lesefehler ! | read - error ! ][ OK ]" );
		
		i = 0;
	 	do{
			/* Beim ersten "jungfr�ulichen" Eintrag haben wir	*/
			/* das Ende des Directorys erreicht:				*/
			if( dir[i].name[0] == (char)0  )
			{
				free( dir );
				return;
			}

			/* Gel�schte Eintr�ge erkennt man am ersten Zeichen	*/
			/* des Dateinamens. Sie werden �bersprungen:		*/
			if( dir[i].name[0] != (char)0xe5 )
			{
				if( dir[i].attr & 16 )
				{
					/* Subdirectories �bergeben wir dem	*/
					/* zust�ndigen Spezialisten:		*/
					tr_subdir( p, fat, mot( dir[i].stclus ), d, drive );
				}
				else
				{
					if( lmot( dir[i].fl ) > 0L )
					{
						/* Dateien ebenfalls - sofern sie	*/
						/* gr��er als 0 Bytes sind !		*/
						trace_fil( fat, mot( dir[i].stclus ) );
						(d->files)++;
					}
				}
			}
		/* Das Spielchen treiben wir notfalls bis	*/
		/* das Clusterende erreicht ist:			*/
		}while( ++i < p->clsizb / 32 );
	}
	free( dir );
}




/****************************************************************/
/* Verfolgen einer Datei										*/
/****************************************************************/
/* Vom �bergebenen Startcluster ausgehend hangelt sich diese	*/
/* Routine durch die FAT, bis eine Clusternummer >= $FFF8 das	*/
/* Ende der	Datei anzeigt:										*/

void trace_fil( unsigned int *f, int start )
{
unsigned int clus;

	do{
		clus = mot( f[start] );
		
		/* Hier merken wir uns, da� der Cluster, an dem wir		*/
		/* eben "vorbeihangelten", ordnungsgem�� belegt ist,	*/
		/* indem wir seinen Eintrag in f[] l�schen. 			*/ 
		f[start] = 0;
		
		start = clus;
	}while( clus < 0xfff8L );
	/* Das war's schon - kurz, gelle ? */
}




/****************************************************************/
/* Verfolgen eines Unterverzeichnisses							*/
/****************************************************************/
/* Unterverzeichnisse sind wie normale Dateien aufgebaut. Ihr	*/
/* Inhalt hat dabei die gleiche Struktur wie das Wurzelver-		*/
/* nis.															*/

void tr_subdir( BPB *p, INTELWD *f, unsigned int start, DRIVE *d, 
				int drive )
{
DIR *dir;						/* Directory im Speicher		*/
unsigned int clus;				/* aktueller Cluster			*/
int i;							/* Z�hler						*/

	(d->subdir)++;

	/* Wir reservieren Platz f�r einen Cluster	*/
	/* voller Directory-Eintr�ge:				*/
	
	if( NULL == (dir = (DIR *)malloc( (size_t)(p->clsizb) )) )
		error( "[3][ malloc() - Fehler ! | malloc() - error ! ][ OK ]" );
	memset( (void *)dir, 0, (size_t)(p->clsizb) );		
	
	do{		
		/* Cluster laden:	*/	
		if( Rwabs( 0, (void *)dir, p->clsiz, p->datrec + (start-2) * p->clsiz, drive ) )
			error( "[3][ Lesefehler ! | Read-error ! ][ OK ]" );
			
		i = 0;
		do{
			/* Gel�schte Eintr�ge werden �bersprungen - das kennen	*/
			/* wir schon vom Wurzelverzeichnis. Neu ist hier, da�	*/
			/* auch die Dateien �bersprungen werden, deren Namen 	*/
			/* mit einem Punkt beginnen. Das sind n�mlich die Ein-	*/
			/* tr�ge der (fiktiven) Dateien '.' und '..', die auf	*/
			/* den Anfang des Unterverzeichnisses und seines Vater-	*/
			/* verzeichnisses zeigen. Wenn wir die auch verfolgen	*/
			/* w�rden, k�nnte das ganze recht langwierig werden...	*/
			/* (Endlosschleife!)									*/
		
			if( dir[i].name[0] != (char)0xe5 && dir[i].name[0] != '.' )
			{
				/* Unbenutzter Eintrag ? Dann gehen wir	davon	*/
				/* aus, da� wir das	Ende der Fahnenstange 		*/
				/* erreicht haben:								*/
				if( dir[i].name[0] == (char)0  )
				{
					f[start] = 0;
					free( dir );
					return;
				}
	
				if( dir[i].attr & 16 )
				{
					/* Weitere Unterverzeichnisse bearbeiten	*/
					/* wir rekursiv:							*/
					tr_subdir( p, f, mot( dir[i].stclus ), d, drive );
				}
				else
				{
					if( lmot( dir[i].fl ) > 0L )
					{
						/* Nur Dateien > 0 Bytes verdienen	*/
						/* unser Interesse:					*/
						trace_fil( f, mot( dir[i].stclus ) );
						(d->files)++;
					}
				}
			}
		/* Notfalls bis zum bitteren Clusterende: */
		}while( ++i < p->clsizb / 32 );
	
		clus = mot( f[start] );	/* n�chste Clusternummer holen	*/
		f[start] = 0;			/* Eintrag l�schen (wichtig!)	*/
		start = clus;
	}while( clus < 0xfff8L );	/* bis ans Dateiende */
	free( dir );
}



/****************************************************************/
/* Wandelt eine Integerzahl im Intel-Format ins Motorola-Format */
/* (und umgekehrt)												*/
/****************************************************************/
/* Es werden einfach nur High- und Lowbyte vertauscht.			*/

unsigned int mot( INTELWD x )
{
	return( ( x << 8 ) + ( x >> 8 ) );
}



/****************************************************************/
/* Wandelt ein Langwort im Intel-Format ins Motorola-Format um	*/
/* ( und nat�rlich auch umgekehrt)								*/
/****************************************************************/
/* Die vier Bytes eines Langwortes werden sozusagen um die		*/
/* Mittelachse gespiegelt. Ihre Reihenfolge wird also genau um-	*/
/* gedreht.														*/

unsigned long lmot( INTELLG x )
{
unsigned char a[4];
unsigned char *b;
	b = (unsigned char *)(&x);
	a[0] = b[3];
	a[1] = b[2];
	a[2] = b[1];
	a[3] = b[0];
	return( *((unsigned long *)a) );
}



/****************************************************************/
/* Das gute alte BASIC-Peek in der ANSII-C-Variante:			*/
/****************************************************************/
/* ( F�r GFA-BASIC-Fans: LPEEK() )								*/
/* Arbeitet im Supervisor-Modus und kann deshalb auch auf die	*/
/* begehrten Systemvariablen angewendet werden.					*/

long peek( long x )
{
long old_super;
long value;
	old_super = Super( 0L );
  	value = *( (long *)x );
	Super( (void *)old_super );
	return( value );
}
