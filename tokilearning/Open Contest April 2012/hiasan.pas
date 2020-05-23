uses math;

var
  n,m,i,j:longint;
  ans:int64;
  sum,a,dia,dp:array[-555..555,-555..555] of int64;

begin
  readln(n,m);
  for i:=1 to n do
    for j:=1 to n do read(a[i,j]);
  for i:=1 to n do
    for j:=1 to n do
      begin
        sum[i][j]:=sum[i][j-1]+a[i][j];
        dia[i-j][i]:=dia[i-j][i-1]+a[i][j];
      end;
  for i:=1 to n do dp[1][i]:=a[1][i];
  for i:=2 to m do
    for j:=1 to n-i+1 do dp[i][j]:=dp[i-1][j]+sum[i][j+i-1]-sum[i][j-1];
  for i:=m+1 to n do
    for j:=1 to n-m+1 do
      dp[i][j]:=dp[i-1][j]+sum[i][j+m-1]-sum[i][j-1]-dia[i-j-m][i-1]+dia[i-j-m][i-m-1];
  ans := -round(1e18);
  for i:=m to n do
    for j:=1 to n-m+1 do
        ans:=max(ans,dp[i][j]);
  writeln(ans);
end.
