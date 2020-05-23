var
t,kasus,i,n,count:integer;
sum:longint;
avg:real;
a:array[1..10000] of integer;

begin
readln(t);
for kasus:=1 to t do
begin
readln(n);
sum:=0;
for i:=1 to n do
begin
read(a[i]);
sum:=sum+a[i];
end;
avg:=sum/n;
count:=0;
for i:=1 to n do
if a[i]<avg then inc(count);
writeln(count);
end;
end.