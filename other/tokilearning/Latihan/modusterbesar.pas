var
  n,i,a,ans:longint;
  m:array[0..1000] of longint;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(a);
      inc(m[a]);
    end;
  ans:=0;
  for i:=1000 downto 1 do
    if m[i]>m[ans] then ans:=i;
  writeln(ans);
end.
