var
n,i,j,max,imax:integer;
a,l,r:array[1..1000] of integer;

begin
readln(n);
for i:=1 to n do read(a[i]);
max:=0;
fillchar(l,sizeof(l),0);
fillchar(r,sizeof(r),0);
for i:=1 to n do
begin
if i=1 then l[i]:=1
else
for j:=1 to i-1 do
  if a[j]<a[i] then
    if l[j]+1>l[i] then l[i]:=l[j]+1;
if l[i]=0 then l[i]:=1;
end;
for i:=n downto 1 do
begin
if i=n then r[i]:=1
else
for j:=n downto i+1 do
  if a[j]<a[i] then
    if r[j]+1>r[i] then r[i]:=r[j]+1;
if r[i]=0 then r[i]:=1;
end;
for i:=1 to n do
begin
if l[i]+r[i]-1>max then
begin
max:=l[i]+r[i]-1;
imax:=i;
end;
end;
writeln(imax,' ',max);
end.