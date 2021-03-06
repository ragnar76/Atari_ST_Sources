DEFINITION MODULE SysBuffers;

(*
 * Dies Modul stellt lediglich Variablen zur Verf�gung, die sich als
 * Stack-Bereich f�r die Verwendung bei einigen MOS-Funktionen eignen.
 *
 * Alle in Frage kommenden MOS-Funktionen haben dazu einen Parameter,
 * meist 'wsp' genannt, vom Typ 'MOSGlobals.MemArea'. Eine Variable
 * dieses Typs ist zu deklarieren und dann wie folgt zu initialisieren
 * (naja, ein Aggregat w�rde es auch tun).
 *
 *   Bsp. f�r Anwendung von CatchErrors:
 *
 *   BEGIN
 *     HdlError.CatchErrors (errorHandlingProcedure,
 *                           MOSGlobals.MEM (SysBuffers.HdlErrorStack));
 *
 * �brigens: Bei CatchProcessTerm, CatchRemoval und SetEnvelope kann
 *    'wsp.bottom' NIL sein, es braucht also kein extra Stack reserviert
 *    werden, weil zum Zeitpunkt der Aufrufe der dort angemeldeten
 *    Prozeduren bereits der normale Programm-Stack verwendet werden kann.
 *)

FROM SYSTEM IMPORT BYTE;

VAR HdlErrorStack: ARRAY [1..2000] OF BYTE;
    (*
     * Dieser Stack kann, sofern er ausreichend gro� ist,
     * f�r alle bei 'HdlError.CatchErrors' angemeldeten
     * verwendet werden.
     *)

VAR ExceptsStack: ARRAY [1..2000] OF BYTE;
    (*
     * Dieser Stack ist f�r die Prozeduren im Modul 'Excepts'
     * vorgesehen.
     *)

END SysBuffers.
