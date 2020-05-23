uses math;
var
  N,i,ans:longint;ch:char;s:string;
  l:array[0..555555] of longint;
  a,b:array[0..555555] of char;
  dp:array[#0..#255,#0..#255] of longint;

begin
  readln(N);
  for i:=1 to n do
    begin
      readln(s);
      a[i]:=s[1];l[i]:=length(s);b[i]:=s[l[i]];
    end;
  for i:=1 to n do
    begin
      for ch:='a' to 'z' do
        if dp[ch][a[i]]>0 then dp[ch][b[i]]:=max(dp[ch][b[i]],dp[ch][a[i]]+l[i]);
      dp[a[i]][b[i]]:=max(dp[a[i]][b[i]],l[i]);
    end;
  for ch:='a' to 'z' do ans:=max(ans,dp[ch][ch]);
  writeln(ans);
end.
