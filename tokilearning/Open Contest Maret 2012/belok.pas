uses math;

var
  r,c,i,j,ans:longint;
  a:array[0..1111,0..1111] of char;
  dp:array[0..1111,0..1111] of longint;

begin
  readln(r,c);
  fillchar(a,sizeof(a),'x');
  for i:=1 to r do
    begin
      for j:=1 to c do read(a[i,j]);
      readln;
    end;
  fillchar(dp,sizeof(dp),255);
  //fill the last column
  for i:=1 to r do
    if a[i,c]='.' then dp[i,c]:=0;
  for j:=c-1 downto 1 do
    for i:=1 to r do
      begin
        if a[i,j]='x' then continue;
        if dp[i,j+1]>=0 then dp[i,j]:=dp[i,j+1];
        if (a[i-1,j]='.') and (dp[i-1,j+1]>=0) then
          if (dp[i,j]<0) or (dp[i,j]>dp[i-1,j+1]+1) then dp[i,j]:=dp[i-1,j+1]+1;
        if (a[i+1,j]='.') and (dp[i+1,j+1]>=0) then
          if (dp[i,j]<0) or (dp[i,j]>dp[i+1,j+1]+1) then dp[i,j]:=dp[i+1,j+1]+1;
      end;
  ans:=maxlongint;
  for i:=1 to r do
    if dp[i,1]>=0 then ans:=min(dp[i,1],ans);
  if ans=maxlongint then writeln(-1) else writeln(ans);
  {
  for i:=1 to r do
    begin
      for j:=1 to c do write(dp[i,j]:4);writeln;
    end;
  }
end.
