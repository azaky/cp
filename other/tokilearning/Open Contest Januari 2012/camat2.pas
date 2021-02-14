var
  n,i,a,b,c,m:longint;
  f:array[0..1000005] of longint;

begin
  readln(n,f[1],f[2],a,b,c,m);
  for i:=3 to n do f[i]:=(a*f[i-1]+b*f[i-2]+c) mod m;
  writeln(f[n]);
end.
