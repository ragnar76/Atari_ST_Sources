/*********************************************************************/
/*   Affichage d'une bo�te de dialogue/Boutons touchexit (UP/DOWN)   */
/*   Megamax Laser C                      DIALOG4.C   */
/*********************************************************************/

#include <obdefs.h>    /* D�finitions des objets GEM */

#include "gem_inex.c"
#include "dialog4.h"   /* Fichier en-t�te du fichier ressource */

OBJECT *arbre_adr;      /* pointeur sur le premier objet d'un arbre */
int    bouton,
       nombre,
       x, y, w, h;
char   entree[80],
       *str = "0";


select (arbre, index)          /* active le bouton "objet" */
OBJECT arbre[];
int    index;
{
  arbre[index].ob_state |= 1;     /* Mettre � 1 le bit 0 de ob_state */ 
}


deselect (arbre, index)       /* inhibe le bouton "objet" */
OBJECT arbre[];
int    index;
{
  arbre[index].ob_state &= -2;    /* Efface le bit 0 de ob_state */ 
}


show_dialog (arbre, x, y, w, h)  /* Affichage d'une bo�te de dialogue */
OBJECT *arbre;
int  *x, *y, *w, *h;
{
  /* Centrer le formulaire sur l'�cran. Seules les coordonn�es sont */
  /* adapt�es � la r�solution de l'�cran. Rien n'est dessin�. Nous  */
  /* recevons les futures coordonn�es de la bo�te de dialogue.      */
  
  form_center (arbre, x, y, w, h);
  
  /* Sauvegarder les cadres des fen�tres, etc: */
  form_dial (0, *x, *y, *w, *h, *x, *y, *w, *h);
  
  /* Dessiner un rectangle zoom� */
  form_dial (1, 25, 25, 25, 25, *x, *y, *w, *h);

  /* Dessin de l'arbre objet */
  /* Commencer par l'objet no 0 (Racine, cadre ext�rieur) */
  /* Profondeur: 12 niveaux maxi (valeur arbitraire) */
  objc_draw (arbre, 0, 12, *x, *y, *w, *h);
}


hide_dialog (arbre)
OBJECT *arbre;
{
int  x, y, w, h;

  /* Redemander les coordonn�es: */
  form_center (arbre, &x, &y, &w, &h);
  
  /* Dessiner un rectangle qui s'�loigne */
  form_dial (2, 25, 25, 25, 25, x, y, w, h);
  
  /* Restituer les cadres des fen�tres et envoyer un message */
  /* Redraw � toutes les fen�tre effac�es                    */
  form_dial (3, x, y, w, h, x, y, w, h);
}


write_text (arbre, index, string)        /* Modifier l'objet TEXT */
OBJECT arbre[];
int    index;
char   string[];
{
TEDINFO *ted;

  ted = (TEDINFO *) arbre[index].ob_spec;
  strcpy (ted->te_ptext, string);
  
  /* ted->te_ptext   correspond �:  (*ted).te_ptext */
}


main()
{
  gem_init();
  
  /* Charger le fichier ressource (DIALOG4.RSC) */
  
  if (rsrc_load ("DIALOG4.RSC") == 0)
    form_alert (1, "[3][Pas de fichier RSC!][Fin]");
  else
  {
    /* Trouver l'adresse de (0 =) l'arbre DIALOG */
    rsrc_gaddr (0, FORM1, &arbre_adr);

    /* Initialisation du champ d'affichage (ACTUEL) */
    write_text (arbre_adr, ACTUEL, "0");

    /* Afficher la bo�te de dialogue */
    show_dialog (arbre_adr, &x, &y, &w, &h);
    
    do
    {
      /* Dialog fait son travail */
      bouton = form_do (arbre_adr, 0);

      switch (bouton)    /* Consulter les boutons de curseur */
      {
        case HAUT:   nombre++;
                    break;
        
        case BAS: nombre--;
                    break;
      }
      
      switch (nombre)    /* Comparer aux limites */
      {
        case -1:  nombre = 9;
                  break;
        
        case 10:  nombre = 0;
                  break;
      }
      
      /* �crire le nombre dans le champ: */
      str[0] = '0' + nombre;
      write_text (arbre_adr, ACTUEL, str);
      
      /* Redessiner uniquement le champ texte (0 niveau inf�rieur) */
      objc_draw (arbre_adr, ACTUEL, 0, x, y, w, h);

      /* Br�ve pause (0.2 secondes) */
      evnt_timer (200, 0);

    } while (bouton != FIN);        
    
    /* D�s�lectionner le bouton */
    deselect (arbre_adr,bouton);

    /* Effacer la bo�te de dialogue */
    hide_dialog (arbre_adr);
         
    /* Effacer le fichier ressource de la m�moire */
    rsrc_free();
  }
  
  gem_exit();
}
