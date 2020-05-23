var
  n:int64;

begin
  readln(n);
  while n mod 2=0 do n:=n div 2;
  writeln(n=1);
end.
