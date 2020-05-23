var
  n,a,b,c,i:longint;

begin
  n := 929;
  a := -2; b := random(10000000); c := random(10000000);
  writeln(n); writeln(a,' ',b,' ',c);
  for i:=1 to n do write(random(100)+1,' ');writeln;
end.
