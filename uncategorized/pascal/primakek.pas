const
  maxn = 1000000;

var
  i,j,nprime,t,k:longint;
  prime:array[1..maxn] of boolean;
  p:array[1..maxn] of longint;

begin
  fillchar(prime,sizeof(prime),true);
  prime[1]:=false;
  for i:=2 to trunc(sqrt(maxn)) do
    if prime[i] then
      for j:=2 to maxn div i do
        prime[i*j]:=false;
  nprime:=0;
  for i:=1 to maxn do
    if prime[i] then
      begin
        inc(nprime);
        p[nprime]:=i;
      end;
  readln(t);
  for i:=1 to t do
    begin
      readln(k);
      writeln(p[k]);
    end;
end.

