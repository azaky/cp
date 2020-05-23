uses math;

var
  n,i,j:longint;
  a,b,c:int64;
  x,sum,dp:array[0..1000000] of int64;

begin
  readln(n); readln(a,b,c);
  for i:=1 to n do read(x[i]);
  for i:=1 to n do sum[i]:=sum[i-1]+x[i];
  for i:=1 to n do
    begin
      dp[i]:=a*sum[i]*sum[i]+c;
      for j:=1 to i-1 do dp[i]:=max(dp[i],dp[j]+a*(sum[i]-sum[j])*(sum[i]-sum[j])+c);
    end;
  //for i:=1 to n do write(dp[i]:5);writeln;
  writeln(dp[n]+b*sum[n]);
end.
