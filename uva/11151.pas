uses math;
var
  tc,kasus,n,i,j:longint;
  dp:array[-1..1000,-1..1000] of longint;
  s:ansistring;

function pal(l,r:longint):longint;
  begin
    if l=r then exit(1);
    if l>r then exit(0);
    if dp[l][r]>=0 then exit(dp[l][r]);
    if s[l]=s[r] then dp[l][r] := pal(l+1,r-1)+2
      else dp[l][r] := max(pal(l+1,r),pal(l,r-1));
    exit(dp[l][r]);
  end;

begin
  readln(tc);
  for kasus:=1 to tc do
    begin
      readln(s); n := length(s);
      for i:=0 to n do
        for j:=0 to n do dp[i][j] := -1;
      writeln(pal(1,n));
    end;
end.
