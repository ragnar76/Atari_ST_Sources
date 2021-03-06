DEFINITION MODULE SystemError;

(*
 * Dieses Modul dient nur zur zur Anzeige von fatalen Fehlern,
 * die unbedingt zum Programmabbruch f�hren, ohne vorher einen
 * Laufzeitfehler auszul�sen!
 *)

FROM SYSTEM IMPORT ADDRESS;

PROCEDURE Abort (error: INTEGER);
 (*
  * Terminiert das Programm.
  * 'error' sollte eine GEMDOS-Fehlernummer sein. Dieser Wert wird normaler-
  * weise als Exitcode geliefert, solange der vom Desktop angezeigt wird.
  * (Das ist der Fall bei Werten zw. -33 und -94).
  * Bei positiven Werten wird der Wert unver�ndert geliefert, soda� auch
  * keine Fehlermeldung vom Desktop angezeigt wird.
  * Bei sonstigen negativen Werten wird ein anderer Wert genommen, damit
  * das Desktop in jedem Fall eine Meldung ausgibt: Ist der Wert in 'error'
  * kleiner als -94, wird -94 geliefert, was den Desktop zur Anzeige
  * "TOS-Error #63" veranla�t.
  * Bei Werten zw. -1 und -32 wird 62 abgezogen, soda� Werte zw. -63 und
  * -94 geliefert werden und entsprechend "TOS-Error #32" bis "#63" an-
  * gezeigt wird.
  *)

PROCEDURE AbortWithMsg (msg: ADDRESS);
 (*
  * Terminiert das Programm.
  * 'msg' ist ein Zeiger auf einen Text, der auf dem Bildschirm
  * ausgegeben wird.
  * Als Exitcode wird immer -1 geliefert, soda� keine weitere Anzeige
  * durch das Desktop erfolgen wird.
  *)

PROCEDURE OutOfMemory;
 (*
  * Terminiert mit Exitcode -39, was den Desktop veranla�t, die Meldung
  * anzuzeigen, da� Speicher f�r diese Anwendung nicht reicht.
  *)

END SystemError.
