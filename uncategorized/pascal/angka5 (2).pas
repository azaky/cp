var
n,n1,n2,i,i1,i2,k,ans:longint;
stat:byte;
a1,a2:array[1..1000001] of longint;
 
begin
readln(n1,n2);
readln(n);
fillchar(a1,sizeof(a1),20000001);
fillchar(a2,sizeof(a2),20000001);
for i:=1 to n1 do read(a1[i]);
for i:=1 to n2 do read(a2[i]);
k:=0;
i1:=1;
i2:=1;
while k<n do
begin
inc(k);
if (i1<=n1) and (a1[i1]<=a2[i2]) then
begin
inc(i1);
stat:=1;
end
else
begin
inc(i2);
stat:=2;
end;
if n=k then
if stat=1 then ans:=a1[i1-1]
else ans:=a2[i2-1];
end;
writeln(ans);
end.
 