const
  abjad='zyxwvutsrqponmlkjihgfedcba';

var
  i:longint;

begin
  assign(output,'test.txt'); rewrite(output);
  for i:=1 to 384 do write('abcdefghijklmnopqrstuvwxyz'); writeln;
  for i:=1 to 38461 do write('zyxwvutsrqponmlkjihgfedcba'); writeln;
  close(output);
end.
