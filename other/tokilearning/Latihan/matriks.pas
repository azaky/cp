var
  n,m,i,j:longint;
  a:array[1..100,1..100] of longint;

begin
  readln(n,m);
  for i:=1 to n do
    for j:=1 to m do read(a[i,j]);
  for i:=1 to m do
    for j:=n downto 1 do
      if j=1 then writeln(a[j,i])
        else write(a[j,i],' ');
end.
