{ time library - Copyright Hartmut Thordsen, V2.2 Dezember 1987 }

{ Die interne Codierung einer Zeit f�r die Library-Routinen  erfolgt  als
  REAL in der Form hh.mmss . Negative Werte sind zul�ssig. Es kommt nicht
  auf die Exaktheit der Mantisse auf den nicht	verwendeten  Stellen  an.
  Vielmehr mu� lediglich die Rundung der 6. Stelle der Mantisse noch  die
  korrekten Sekunden ergeben. }

PROCEDURE hms_time (h, m, s : INTEGER; VAR t : REAL);		EXTERNAL;
PROCEDURE time_hms (t : REAL; VAR h, m, s : INTEGER);		EXTERNAL;
  { hms_time gibt die mit Stunden, Minuten und Sekunden  �bergebene  Zeit
  in der Form hh.mmss zurueck; es erfolgt keine Plausibilit�tspr�fung der
  �bergebenen Werte. time_hms ist die Umkehrfunktion. Negative Vorzeichen
  der  �bergebenen  Werte  werden ignoriert; die Ergebniswerte sind stets
  positiv. }

FUNCTION systime_time (stime : INTEGER) : REAL; 		EXTERNAL;
FUNCTION time_systime (time : REAL) : INTEGER;			EXTERNAL;
  { systime_time macht aus einer im System bitweise codierten Zeit (siehe
  GEMDOS-Funktionen) ein REAL mit der Form hh.mmss . Die Funktion  time_-
  systime codiert das �bergebene Real-Datum f�r's System. }

FUNCTION get_time : REAL;					EXTERNAL;
PROCEDURE set_time (time : REAL);				EXTERNAL;
  { get_time liefert die eingestellte Systemzeit in der Form hh.mmss .
  set_time setzt die Systemzeit. }

FUNCTION time_dec (time : REAL) : REAL; 			EXTERNAL;
FUNCTION dec_time (dec : REAL) : REAL;				EXTERNAL;
  { time_dec erzeugt aus der  �bergebenen Zeit der Form hh.mmss eine  De-
  zimalzahl, d.h. die Minuten und Sekunden werden  als	gebrochener  Teil
  einer Stunde auf den Nachkommastellen berechnet.  dec_time ist die  Um-
  kehrfunktion. }

FUNCTION add_time (time1, time2 : REAL) : REAL; 		EXTERNAL;
FUNCTION sub_time (time1, time2 : REAL) : REAL; 		EXTERNAL;
  { add_time liefert die Summe der beiden Zeiten in der Form hh.mmss  als
  Funktionswert; sub_time hat time1 - time2 als Ergebnis. }

FUNCTION time_ok (time : REAL) : BOOLEAN;			EXTERNAL;
  { time_ok liefert TRUE, wenn die  �bergebene Zeit der Form hh.mmss auch
  einer Zeit entspricht, d.h. mm und ss m�ssen	zwischen 0 und 59 liegen.
  Andernfalls wird der Wert FALSE zur�ckgegeben. Der Wert f�r die Stunden
  ist beliebig, kann also auch gr��er als 23 sein. }

FUNCTION str_time (s : STRING; VAR time : REAL) : BOOLEAN;	EXTERNAL;
  { str_time erzeugt aus dem  �bergebenen  String s  eine Real-Zeit   der
  Form hh.mmss . s darf nur aus Ziffern und den Zeichen  ':' und  '.' be-
  stehen und mu� in einem der folgenden Formate vorliegen:
	hhmm	     Neben den Zeichen mu�  auch das Format stimmen. Aus-
	hh:mm	     serdem wird die Plausibilit�t  gepr�ft  (siehe  auch
	hhmmss	     time_ok). Wenn alles stimmt, steht das  Ergebnis  in
	hh:mm:ss     time; die Funktion hat den Wert  TRUE.  Bei  Fehlern
	mm.ss	     ist der Wert der Funktion FALSE;  time  bleibt  dann
		     unver�ndert.
  Die Zeichen '.' und ':' haben Trennfunktion. D.h. bei  diesen  Formaten
  kann die Anzahl der Stellen f�r  hh, mm oder ss von zwei abweichen; der
  Wertebereich f�r Integer darf jedoch nicht verletzt werden. }

PROCEDURE time_str (time : REAL; width : INTEGER; VAR s : STRING);
								EXTERNAL;
  { erzeugt in s einen String der L�nge width mit der Zeit in der Form
	width <= 1  :
   2 <= width <= 4  :  hh	   Die Zeit wird linksb�ndig eingetragen.
   5 <= width <= 7  :  hh:mm
   8 <= width	    :  hh:mm:ss  }

