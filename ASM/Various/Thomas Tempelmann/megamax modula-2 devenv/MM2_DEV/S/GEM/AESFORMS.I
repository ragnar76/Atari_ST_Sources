IMPLEMENTATION MODULE AESForms; (*$L-, N+, Y+*)


(*  Megamax Modula-2 GEM-Library :  Die AES Formularfunktionen
 *
 *  Autor: Manuel Chakravarty           Erstellt :  05.11.87
 *
 *  Version   2.2     V#0018
 *)
 
(*  05.11.87    | �bernahme von 'GEMBase' und 'GEMExt'
 *  22.02.89    | Stack wird von 'FormButton' und 'FormKeyboard' jetzt
 *                richtig abger�umt.
 *  27.06.89    | Sch�nheitsoperationen
 *  ???????? TT | REF-Parm.
 *  02.04.90    | Anpassung an public arrays
 *  01.02.91 TT | FormAlert: Null-Terminierung raus, da unn�tig.
 *  08.04.91 TT | FormKeyboard: 'ch' & 'nextObj' endlich vertauscht.
 *)


FROM    SYSTEM          IMPORT ASSEMBLER;

FROM    GrafBase        IMPORT Rectangle;

FROM    GEMGlobals      IMPORT PtrObjTree, GemChar;
 
IMPORT  GEMShare;


(*$I GEMOPS.ICL *)
 
 
PROCEDURE FormCenter (tree: PtrObjTree): Rectangle;

  BEGIN
    ASSEMBLER
        MOVE.L      pubs,A0
        MOVE.L      -(A3),pubArrays.ADDRIN(A0)
        MOVE.W      #FORM_CENTER,(A3)+
        JSR         aes_if
        MOVE.L      pubs,A0
        MOVE.L      pubArrays.aINTOUT+2(A0),(A3)+
        MOVE.L      pubArrays.aINTOUT+6(A0),(A3)+
     END;
   END FormCenter;
    
PROCEDURE FormDial (flag: FormDialMode; little, big: Rectangle);

  BEGIN
    ASSEMBLER
        MOVE.L      pubs,A0
        LEA         pubArrays.aINTIN+18(A0),A0
        MOVEQ       #3,D0
loop
        MOVE.L      -(A3),-(A0)
        DBF         D0,loop
        MOVE.W      -(A3),-(A0)
        MOVE.W      #FORM_DIAL,(A3)+
        JSR         aes_if
        ;JSR         testINTOUT0 !!!  GEM bringt immer aINTOUT[0]=0, ohne Grund!
    END;
  END FormDial;
        
PROCEDURE FormDo (tree: PtrObjTree; first: CARDINAL; VAR retBut: CARDINAL);

  BEGIN
    ASSEMBLER
        MOVE.L  -(A3),-(A7)
        
        MOVE.L  pubs,A0
        MOVE.W  -(A3),pubArrays.aINTIN(A0)
        MOVE.L  -(A3),pubArrays.ADDRIN(A0)
        MOVE.W  #FORM_DO,(A3)+
        JSR     aes_if
        
        MOVE.L  pubs,A0
        MOVE.L  (A7)+,A1
        MOVE.W  pubArrays.aINTOUT(A0),(A1)
    END;
  END FormDo;

PROCEDURE FormAlert (    defBut: CARDINAL;
                     REF str   : ARRAY OF CHAR;
                     VAR retBut: CARDINAL);

  BEGIN
    ASSEMBLER
        MOVE.L      -(A3),-(A7)
        ; nicht n�tig: JSR         stringIntoCFormat   ; schiebe string mit #0 auf den A7-Stack
        ; stattdessen:
        SUBQ.L      #2,A3
        MOVE.L      -(A3),D2
        MOVE.L      pubs,A0
        MOVE.L      D2,pubArrays.ADDRIN(A0)    ; ADR(astring) steht nach 'stringIn..' in D2
        MOVE.W      -(A3),pubArrays.aINTIN(A0)
        MOVE.W      #FORM_ALERT,(A3)+
        JSR         aes_if
        ; nicht n�tig (s.o.): MOVE.L      (A7),A7             ; String wieder vom Stack entfernen
        MOVE.L      (A7)+,A1
        MOVE.L      pubs,A0
        MOVE.W      pubArrays.aINTOUT(A0),(A1)
    END;
  END FormAlert;

PROCEDURE FormError (errNo: INTEGER);

  BEGIN
    ASSEMBLER
        MOVE.L      pubs,A0
        MOVE.W      -(A3),pubArrays.aINTIN(A0)
        MOVE.W      #FORM_ERROR,(A3)+
        JSR         aes_if
    END;
  END FormError;

PROCEDURE FormKeyboard (    tree   : PtrObjTree;
                            index  : CARDINAL;
                        VAR nextObj: CARDINAL;
                        VAR ch     : GemChar;
                        VAR cont   : BOOLEAN);

  BEGIN
    ASSEMBLER
        MOVE.L  -(A3),-(A7)     ; cont
        MOVE.L  -(A3),A1        ; ch
        MOVE.L  A1,-(A7)
        MOVE.L  -(A3),-(A7)     ; nextObj
        
        MOVE.L  pubs,A0
        MOVE.W  -(A3),pubArrays.aINTIN(A0)
        MOVE.L  -(A3),pubArrays.ADDRIN(A0)
        MOVE.W  (A1),pubArrays.aINTIN+2(A0)  ; ch
        CLR.W   pubArrays.aINTIN+4(A0)
        MOVE.W  #FORM_KEYBD,(A3)+
        JSR     aes_if
        
        MOVE.L  pubs,A0
        MOVE.L  (A7)+,A1        ; VAR nextObj
        MOVE.W  pubArrays.aINTOUT+2(A0),(A1)
        MOVE.L  (A7)+,A1        ; VAR ch
        MOVE.W  pubArrays.aINTOUT+4(A0),(A1)
        
        TST.W   pubArrays.aINTOUT(A0)
        SNE     D0
        ANDI.W  #1,D0
        MOVE.L  (A7)+,A1
        MOVE.W  D0,(A1)
    END;
  END FormKeyboard;
                        
PROCEDURE FormButton (    tree   : PtrObjTree;
                          index  : CARDINAL;
                          clicks : CARDINAL;
                      VAR nextObj: CARDINAL;
                      VAR cont   : BOOLEAN);
                      
  BEGIN
    ASSEMBLER
        MOVE.L  -(A3),-(A7)
        MOVE.L  -(A3),A1
        MOVE.L  A1,-(A7)
        
        MOVE.L  pubs,A0
        MOVE.W  -(A3),pubArrays.aINTIN+2(A0)
        MOVE.W  -(A3),pubArrays.aINTIN(A0)
        MOVE.L  -(A3),pubArrays.ADDRIN(A0)
        MOVE.W  #FORM_BUTTON,(A3)+
        JSR     aes_if
        
        MOVE.L  pubs,A0
        MOVE.L  (A7)+,A1
        MOVE.W  pubArrays.aINTOUT+2(A0),(A1)
        
        TST.W   pubArrays.aINTOUT(A0)
        SNE     D0
        ANDI.W  #1,D0
        MOVE.L  (A7)+,A1
        MOVE.W  D0,(A1)
    END;
  END FormButton;


END AESForms. 
(* $FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$00000393$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3$FFF8BCD3�$00000F68T.......T.......T.......T.......T.......T.......T.......T.......T.......T.......$FFEB25DC$FFEB25DC$00000F04$00000F15$00000EE8$00000ED5$00000EF2$FFEB25DC$00000FCA$00001021$FFEB25DC$00000E34$00000E50$FFEB25DC$00000D9B$00000F68���*)
