var
  n,i:longint;ans:int64;

begin
  readln(n); n:=n div 2;
  ans:=1;
  for i:=1 to n do ans:=((4*i-2)*ans) div (i+1);
  writeln(ans);
end.
