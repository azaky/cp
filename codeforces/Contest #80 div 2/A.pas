const
  add:array[1..11] of longint = (4,4,4,4,4,4,4,4,4,15,4);

var
  n:integer;

begin
  readln(n); n:=n-10;
  if (n<=0) or (n>11) then writeln(0) else writeln(add[n]);
end.