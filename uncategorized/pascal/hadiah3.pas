var
  n,m,p:int64;
  t,i:integer;
  a:array[1..1000] of int64;

begin
  readln(n); m:=0; p:=1;
  while n>0 do
    begin
      t:=n mod 3;
      for i:=1 to t do
        begin
          inc(m); a[m]:=p;
        end;
      n:=n div 3; p:=p*3;
    end;
  writeln(m);
  for i:=1 to m do
    if i=m then writeln(a[i])
      else write(a[i],' ');
end.

