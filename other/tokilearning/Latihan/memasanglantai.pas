var
  n,i:longint;
  dp:array[-3..111111] of longint;

begin
  readln(N);
  dp[0]:=1;
  for i:=1 to n do dp[i]:=(dp[i-1]+dp[i-3]) mod 1000000;
  writeln(dp[n]);
end.
