var
  n,k,i,j,ii:longint;
  dp:array[0..111,0..3,0..3] of int64;
  ans:int64;
begin
  readln(n);
  if n=1 then begin writeln(3); halt; end;
  for i:=1 to 3 do
    for j:=1 to 3 do
      dp[2][i][j]:=1;
  for k:=3 to n do
    for i:=1 to 3 do
      for j:=1 to 3 do
        begin
          dp[k][i][j]:=0;
          for ii:=1 to 3 do
            if ii*i*j=6 then continue
              else inc(dp[k][i][j],dp[k-1][ii][i]);
        end;
  ans:=0;
  for i:=1 to 3 do
    for j:=1 to 3 do
      inc(ans,dp[n][i][j]);
  writeln(ans);
end.
