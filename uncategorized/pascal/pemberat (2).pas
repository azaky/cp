var
  b,k,n,m:int64;

begin
  readln(b); readln(k);
  n:=k-b;
  m:=1; while m<=n do m:=m*2; m:=m div 2;
  //m:=trunc(exp(trunc(ln(n)/ln(2))*ln(2))+0.5);
  while n>0 do
    begin
      while n<m do m:=m div 2;
      n:=n-m; writeln(m);
    end;
end.

