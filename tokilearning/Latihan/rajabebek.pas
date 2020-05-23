uses math;

var
  n,y,i,j,k,a:longint;
  dp,x:array[0..1111] of longint;

begin
  readln(n,y);
  for i:=1 to n do begin read(a); inc(x[a]); end;
  for i:=1 to y do x[i] := min(x[i],y div i);
  for i:=1 to y do dp[i] := 1111; dp[0] := 0;
  for i:=1 to y do
    for j:=1 to x[i] do
      for k:=y downto i do dp[k] := min(dp[k],dp[k-i]+1);
  if dp[i]=1111 then writeln(-1) else writeln(dp[i]);
end.
