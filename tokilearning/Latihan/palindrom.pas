uses math;
var
  tc,kasus,n,i,len,j,ans:longint;
  s:ansistring;
  dp:array[0..1111,0..1111] of longint;

begin
  readln(kasus);
  for tc:=1 to kasus do
    begin
      readln(s);n:=length(s);
      for i:=1 to n do dp[i][i] := 1;
      for len:=2 to n do
        for i:=1 to n-len+1 do
          begin
            j:=i+len-1;
            if s[i]<>s[j] then dp[i][j]:=max(dp[i+1][j],dp[i][j-1])
            else dp[i][j]:=dp[i+1][j-1]+2;
          end;
      ans := 0;
      for i:=1 to n do
        for j:=1 to n do ans := max(ans,dp[i][j]);
      writeln(ans);
    end;
end.
