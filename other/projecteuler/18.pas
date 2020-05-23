uses math;

var
  ans,n,i,j:longint;
  a,m:array[0..1000,0..1000] of longint;

begin
  n:=15;
  for i:=1 to n do
    for j:=1 to i do read(a[i,j]);
  m[1,1]:=a[1,1];
  for i:=2 to n do
    for j:=1 to i do
	  m[i,j]:=a[i,j]+max(m[i-1,j-1],m[i-1,j]);
  for i:=1 to n do
    if m[n,i]>ans then ans:=m[n,i];
  writeln(ans);
end.
