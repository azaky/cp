uses math;

var
  m,n,k,i,j,ans:longint;
  sum,sumk,dp1,dp2,dp3,dp4:array[0..1501,0..1501] of longint;
  dp5,dp6,dp7,dp8:array[0..1501] of longint;

begin
  readln(m,n,k);
  for i:=1 to m do
    for j:=1 to n do
      begin
        read(sum[i][j]);
        sum[i,j]:=sum[i-1,j]+sum[i,j-1]+sum[i,j]-sum[i-1,j-1];
      end;
  for i:=k to m do
    for j:=k to n do sumk[i,j]:=sum[i,j]+sum[i-k,j-k]-sum[i-k,j]-sum[i,j-k];
  for i:=k to m do
    for j:=k to n do dp1[i][j]:=max(max(dp1[i-1][j],dp1[i][j-1]),sumk[i][j]);
  for i:=k to m do
    for j:=n-k+1 downto 1 do dp2[i][j]:=max(max(dp2[i-1][j],dp2[i][j+1]),sumk[i][j+k-1]);
  for i:=m-k+1 downto 1 do
    for j:=k to n do dp3[i][j]:=max(max(dp3[i][j-1],dp3[i+1][j]),sumk[i+k-1][j]);
  for i:=m-k+1 downto 1 do
    for j:=n-k+1 downto 1 do dp4[i][j]:=max(max(dp4[i+1][j],dp4[i][j+1]),sumk[i+k-1][j+k-1]);
  for i:=k to m do
    begin
      dp5[i]:=dp5[i-1];
      for j:=k to n do dp5[i]:=max(dp5[i],sumk[i][j]+max(max(dp1[i-k][j],dp1[i][j-k]),dp2[i][j+1]));
    end;
  for j:=k to n do
    begin
      dp6[j]:=dp6[j-1];
      for i:=k to m do dp6[j]:=max(dp6[j],sumk[i][j]+max(max(dp1[i-k][j],dp1[i][j-k]),dp3[i+1][j]));
    end;
  for i:=m-k+1 downto 1 do
    begin
      dp7[i]:=dp7[i+1];
      for j:=k to n do dp7[i]:=max(dp7[i],sumk[i+k-1][j]+max(max(dp3[i][j-k],dp3[i+k][j]),dp4[i][j+1]));
    end;
  for j:=n-k+1 downto 1 do
    begin
      dp8[j]:=dp8[j+1];
      for i:=k to m do dp8[j]:=max(dp8[j],sumk[i][j+k-1]+max(max(dp4[i+1][j],dp2[i][j+k]),dp2[i-k][j]));
    end;
  for i:=k to m do
    for j:=k to n do
      ans:=max(ans,sumk[i,j]+max(max(dp5[i-k],dp6[j-k]),max(dp7[i+1],dp8[j+1])));
  writeln(ans);
end.
