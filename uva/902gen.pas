var
  i,j:longint;

begin
  randomize;
  for i := 1 to 10 do
    begin
      write('10 ');
      for j := 1 to 1000000 do
        write(chr(ord('a')+random(26)));
      writeln;
    end;
end.
