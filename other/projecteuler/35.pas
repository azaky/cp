const
  maxn = 1000005;

var
  i,j,ans:longint;
  prime:array[0..maxn] of boolean;
  p:array[0..10] of longint;

function circ(x:longint):boolean;
  var
    n,t:longint;
  
  begin
    n:=trunc(ln(x)/ln(10));
    t:=p[n]*(x mod 10)+x div 10;
    while t<>x do
      begin
        if not prime[t] then exit(false);
        t:=p[n]*(t mod 10)+t div 10;
      end;
    writeln(x);
    exit(true);
  end;

begin
  //sieve algorithm
  for i:=2 to maxn do prime[i]:=true;
  for i:=2 to trunc(sqrt(maxn)) do
    if prime[i] then
      for j:=2 to (maxn div i) do prime[i*j]:=false;
  p[0]:=1;
  for i:=1 to 7 do p[i]:=10*p[i-1];
  for i:=2 to 999999 do
    if prime[i] then
      if circ(i) then inc(ans);
  writeln(ans);
end.
