(*$C-*)
module disktest; (*$E mos *)

from randomgen import randomcard;
from sysutil0 import varequal;
from files import file, access, replacemode, open, create, close;
from binary import readblock, writeblock;
import tosio; from inout import WriteString, write, writecard, keypressed,
        writeln;

const a = 10000;

var bl2, bl: array [1..a] of CARDINAL;
    i,j: CARDINAL;
    n: LONGCARD;
    f: file;
    

begin
  n:= 0;
  repeat
    for i:= 1 to a do
      bl [i]:= randomcard (0,maxcard)
    end;
    for j:= 1 to 10 do
      inc (n);
      write (33c);
      write ('H');
      writecard (n,7);
      create (f, 'e:\test.dat', writeonly, replaceold);
      writeblock (f, bl);
      close (f);
      open (f, 'e:\test.dat', readonly);
      readblock (f, bl2);
      close (f);
      if ~varequal (bl, bl2) then
        writeln;
        WriteString ('fehler !');
        halt
      end;
      if keypressed () then return end
    end
  until false
end disktest.
 
(* $FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$00000377$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2$FFF631A2�$000001D1T.......T.......T.......T.......T.......T.......T.......T.......T.......T.......$000003EC$000003D2$00000377$000001D1$00000283$000000E8$00000107$FFF631A2$FFF631A2$FFF631A2$000001D1$0000017A$000001A0$0000022B$000003DB$FFF631A2���*)
