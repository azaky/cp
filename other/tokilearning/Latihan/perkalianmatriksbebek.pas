var
  n,i,j,len,k,task:longint;
  temp:int64;
  a:array[0..111] of int64;
  dp:array[1..3,0..111,0..111] of int64;

begin
  readln(N);
  for i:=1 to n+1 do read(a[i]);
  for i:=1 to n do dp[1][i][i] := 0;
  for i:=1 to n do dp[2][i][i] := 1;
  for i:=1 to n do dp[3][i][i] := 1;
  for len:=2 to n do
    for i:=1 to n-len+1 do
      begin
        j := len+i-1; dp[1][i][j]:=high(int64); dp[2][i][j]:=0;
        for k:=i to j-1 do
          begin
            temp := dp[1][i][k]+dp[1][k+1][j]+a[i]*a[k+1]*a[j+1];
            if temp<dp[1][i][j] then
              begin
                dp[1][i][j] := temp;
                dp[2][i][j] := (dp[2][i][k]*dp[2][k+1][j]) mod 26101991;
              end
            else if temp=dp[1][i][j] then
              begin
                dp[2][i][j] := (dp[2][i][j]+dp[2][i][k]*dp[2][k+1][j]) mod 26101991;
              end;
            dp[3][i][j]:=(dp[3][i][j]+dp[3][i][k]*dp[3][k+1][j]) mod 26101991;
          end;
      end;
  read(task);
  writeln(dp[task][1][n]);
end.
