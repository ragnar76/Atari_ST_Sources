DEFINITION MODULE BinOps;

FROM SYSTEM IMPORT ADDRESS;

(* Folgende f�nf Funktionen liefern den kleineren der beiden Werte *)

PROCEDURE LowerCard (a,b: CARDINAL): CARDINAL;

PROCEDURE LowerInt (a,b: INTEGER): INTEGER;

PROCEDURE LowerLCard (a,b: LONGCARD): LONGCARD;

PROCEDURE LowerLInt (a,b: LONGINT): LONGINT;

PROCEDURE LowerAddr (a,b: ADDRESS): ADDRESS;

(* Folgende f�nf Funktionen liefern den gr��eren der beiden Werte *)

PROCEDURE HigherCard (a,b: CARDINAL): CARDINAL;

PROCEDURE HigherInt (a,b: INTEGER): INTEGER;

PROCEDURE HigherLCard (a,b: LONGCARD): LONGCARD;

PROCEDURE HigherLInt (a,b: LONGINT): LONGINT;

PROCEDURE HigherAddr (a,b: ADDRESS): ADDRESS;

(* Folg. f�nf Funktionen liefern den Wert in 'a', wenn TRUE *)
(* �bergeben wird, sonst liefern sie den Wert in 'b'.       *)

PROCEDURE SwitchCard (condition: BOOLEAN; true, false: CARDINAL): CARDINAL;

PROCEDURE SwitchInt (condition: BOOLEAN; true, false: INTEGER): INTEGER;

PROCEDURE SwitchLCard (condition: BOOLEAN; true, false: LONGCARD): LONGCARD;

PROCEDURE SwitchLInt (condition: BOOLEAN; true, false: LONGINT): LONGINT;

PROCEDURE SwitchAddr (condition: BOOLEAN; true, false: ADDRESS): ADDRESS;

END BinOps.
