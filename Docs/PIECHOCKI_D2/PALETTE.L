
               TEXT

               INCLUDE       "INIT_TOS.L"
               INCLUDE       "MACROS.L"
               INCLUDE       "TIMERS.L"

               SETBLOCK

               SUPER

               PRINTLINE     CA
               WAIT
               TIMERA        ROUTINE,200,%111

               USER
               KEEP          2000

ROUTINE        cmpi          #30,TESTE
               bgt           DEUX
               move.l        #PAL1,$45A
               add           #1,TESTE
               bclr          #5,$FFFA0F
               RTE
DEUX           move.l        #PAL2,$45A
               add           #1,TESTE
               cmpi          #60,TESTE
               bne           NON
               move          #0,TESTE
NON            bclr          #5,$FFFA0F
               RTE

               DATA

PAL1           DC.W          $777,$700,$070,$000,$000,$777,$777,$777
               DC.W          $777,$777,$777,$777,$777,$777,$777,$777

PAL2           DC.W          $777,$700,$007,$000,$000,$777,$777,$777
               DC.W          $777,$777,$777,$777,$777,$777,$777,$777

CA             DC.B          27,'E','Routine sous interruption (TIMER A )'
               DC.B          ' qui change la',13,10,'couleur nr�3 de la'
               DC.B          ' palette (Variable syst�me $45A):',0

               BSS

               DS.B          500
PILE           DS.B          1
SAUV_SP        DS.L          1
TESTE          DS.W          1


               END
 