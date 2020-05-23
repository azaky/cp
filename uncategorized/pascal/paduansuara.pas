var
  m,n,i:integer;
  a,b:array[1..10000] of integer;

procedure sort;
  var
    i,j:integer;

  procedure swap(var int1,int2:integer);
    var
      temp:integer;

    begin
      temp:=int1;
      int1:=int2;
      int2:=temp;
    end;

  begin
    for i:=m downto 1 do
      for j:=1 to i-1 do
        if a[j]>a[j+1] then swap(a[j],a[j+1]);
  end;

begin
  readln(m);
  for i:=1 to m do readln(a[i]);
  readln(n);
  sort;
  for i:=((m mod n)+1) to n do b[i]:=i*(m div n)+(m mod n);
  for i:=1 to (m mod n) do b[i]:=i*(m div n)+i;
  for i:=1 to (n-1) do
    if i=n-1 then writeln(a[b[i]]+1)
      else write(a[b[i]]+1,' ');
end.