               
               TEXT

               INCLUDE       "INIT_TOS.L"
               INCLUDE       "MACROS.L"

               SETBLOCK

               PRINTLINE     MESSAGE
               WAIT
               PRINTLINE     EFFACE
               PEXEC         ZERO,NUL,PRG,#0

               PRINTLINE     RETOUR
               WAIT
               TERM

               DATA

MESSAGE        DC.B          27,'E',7,'Je vais charger le programme SON.PRG'
               DC.B          ' ,je resterais en m�moire et quand le',13,10
               DC.B          'programme se terminera il me redonnera la '
               DC.B          'main car je suis le PRG PERE :',0
EFFACE         DC.B          27,'E','Je charge le PRG FILS :',0
RETOUR         DC.B          27,'E','PRG PERE:   COUCOU !!! me revoil� ...',0

NUL            DC.B          0
ZERO           DC.B          0
PRG            DC.B          'A:\SON.PRG',0    ;nom du programme FILS

               BSS

               DS.B          200
PILE           DS.B          1

               END


 