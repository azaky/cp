var
  n,i,ans,j:longint;
  a,b,pos,dp:array[0..1111] of longint;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do pos[b[i]] := i;
  for i:=1 to n do
    begin
      dp[i] := 1;
      for j:=i-1 downto 1 do
        if pos[a[i]]>pos[a[j]] then
          if dp[j]+1 > dp[i] then dp[i]:=dp[j]+1;
      if dp[i]>ans then ans := dp[i];
    end;
  writeln(ans);
end.
