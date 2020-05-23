uses math;

var
  n,k,i,kk:longint;
  a,dp,temp:array[0..111111] of longint;

begin
  readln(n,k);
  for i:=1 to n do readln(a[i]);
  for kk:=1 to k do
    begin
      for i:=2*kk-2 to n do temp[i]:=dp[i];
      dp[2*kk-1]:=maxlongint;
      for i:=2*kk to n do dp[i]:=min(dp[i-1],temp[i-2]+a[i]-a[i-1]);
      writeln(dp[n]);
    end;
  writeln(dp[n]);
end.
