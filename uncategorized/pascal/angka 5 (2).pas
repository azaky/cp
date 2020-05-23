var
n1,n2,n,i:longint;
a:array[1..2000000] of longint;
 
procedure sort(l,r:longint);
var
i,j,p,temp:longint;
begin
i:=l;
j:=r;
p:=a[(l+r) div 2];
repeat
while a[i]<p do inc(i);
while a[j]>p do dec(j);
if not(i>j) then
begin
temp:=a[i];
a[i]:=a[j];
a[j]:=temp;
inc(i);
dec(j);
end;
until i>j;
if l<j then sort(l,j);
if i<r then sort(i,r);
end;
 
begin
readln(n1,n2);
readln(n);
for i:=1 to n1 do read(a[i]);
for i:=1 to n2 do read(a[n1+i]);
sort(1,n1+n2);
writeln(a[n]);
end.