var
  m,k,i,ans:longint;
  a:array[0..1000000] of longint;

begin
  readln(m); k:=0;
  while m>1 do
    begin
      inc(k); a[k]:=trunc(sqrt(m)); m:=m-trunc(sqrt(m));
    end;
  ans:=1;
  for i:=k downto 1 do
    begin
      m:=m+a[i];
      if sqr(round(sqrt(m)))=m then ans:=ans+a[i]-1 else ans:=ans+a[i];
    end;
  writeln(ans);
end.
