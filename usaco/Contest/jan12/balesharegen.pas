var
  i:longint;

begin
  assign(output,'baleshare.in'); rewrite(output);
  randomize; writeln(20);
  for i:=1 to 20 do writeln(random(100)+1);
  close(output);
end.
