var
  i,n:integer;
  sum:int64;

begin
  readln(n);
  sum:=0;
  for i:=n to n do sum:=sum+(i*i*i*i);
  writeln(sum);
end.