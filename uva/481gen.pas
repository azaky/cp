var
  n,i:longint;

begin
  readln(N); randomize;
  for i:=1 to n do writeln(random(20000)-10000);
end.
