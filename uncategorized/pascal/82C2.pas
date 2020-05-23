var
  n,m,d0,c0,i,j,k,best:longint;
  a,b,c,d,r:array[1..11] of longint;
  price:array[0..1000] of longint;

begin
  readln(n,m,c0,d0);
  for i:=1 to m do readln(a[i],b[i],c[i],d[i]);
  for i:=1 to m do r[i]:=a[i] div b[i];
  inc(m); r[m]:=n div c0; c[m]:=c0; d[m]:=d0;
  for j:=1 to m do
    for i:=n downto 0 do
	  for k:=1 to r[j] do
	    if i-k*c[j]<0 then continue
		  else if price[i]<price[i-k*c[j]]+k*d[j] then
		    price[i]:=price[i-k*c[j]]+k*d[j];
  best:=0;
  for i:=0 to n do
    if price[i]>best then best:=price[i];
  writeln(best);
end.
