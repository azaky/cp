var
  n,i,j:integer;
  a:array[1..10,1..10] of integer;
  
begin
  readln(n);
  for i:=1 to n do read(a[i,1]);
  for i:=n-1 downto 1 do
    for j:=2 to n+1-i do a[i,j]:=a[i+1,j-1]-a[i,j-1];
  for i:=1 to n do
    if i=n then writeln(a[1,i])
      else write(a[1,i],' '); 
end.
