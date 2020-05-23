var
  t,kasus,n,m,i:integer;
  f:array[-1..10000] of integer;

begin
  f[-1]:=0;
  f[0]:=1;
  for i:=1 to 10000 do f[i]:=(f[i-1]+f[i-2]) mod 10000;
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n,m);
      if n<m then writeln(0)
        else if m=0 then writeln(f[n-2])
          else writeln(f[n-m]);
    end;
end.
