var
  n,m,r,i,j,k,c,s,t,temp:longint;
  time,ans:array[0..60,0..60,0..60] of longint;
  dp:array[0..60,0..60,0..60,0..60] of longint;

begin
  read(n,m,r);
  for i:=1 to m do
    for j:=1 to n do
      for k:=1 to n do read(time[i][j][k]);
  for s:=1 to n do
    for t:=1 to n do
      for c:=1 to m do
        dp[0][s][t][c]:=time[c][s][t];
  for c:=1 to m do
    for i:=1 to n do
      for s:=1 to n do
        for t:=1 to n do
          if dp[0][s][t][c]>dp[0][s][i][c]+dp[0][i][t][c] then dp[0][s][t][c]:=dp[0][s][i][c]+dp[0][i][t][c];
  for s:=1 to n do
    for t:=1 to n do
      begin
        ans[0][s][t] := maxlongint;
        for c:=1 to m do
          if dp[0][s][t][c]<ans[0][s][t] then ans[0][s][t] := dp[0][s][t][c];
      end;
  for k:=1 to n do
    begin
      for s:=1 to n do
        for t:=1 to n do
          begin
            if s=t then
              begin
                fillchar(dp[k][s][t],sizeof(dp[k][s][t]),0);
                ans[k][s][t] := 0;
                continue;
              end;
            ans[k][s][t] := maxlongint;
            for c:=1 to m do
              begin
                dp[k][s][t][c]:=maxlongint;
                for i:=1 to n do
                  begin
                    temp := ans[k-1][s][i] + dp[0][i][t][c];
                    if temp < dp[k][s][t][c] then dp[k][s][t][c] := temp;
                  end;
                if dp[k][s][t][c]<ans[k][s][t] then ans[k][s][t] := dp[k][s][t][c];
              end;
          end;
    end;
  for i:=1 to r do
    begin
      read(s,t,k); if k>n then k:=n;
      writeln(ans[k][s][t]);
    end;
end.
