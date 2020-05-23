var
i,n,l,r:longint;
a:array[0..1001] of integer;
 
begin
readln(n);
for i:=1 to n do readln(a[i]);
for i:=1 to n do
begin
l:=i;
r:=i;
while (l-1>0) and (a[l-1]<a[i]) do dec(l);
while (r+1<=n) and (a[r+1]<a[i]) do inc(r);
writeln((i-l+1)*(r-i+1));
end;
end.