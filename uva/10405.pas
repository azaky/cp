uses math;
var
  na,nb,i,j:longint;
  a,b:ansistring;
  dp:array[0..1001,0..1001] of longint;

function lcs(ia,ib:longint):longint;
  begin
    if ia>na then exit(0);
    if ib>nb then exit(0);
    if dp[ia][ib]>=0 then exit(dp[ia][ib]);
    if a[ia]=b[ib] then dp[ia][ib] := 1 + lcs(ia+1,ib+1)
      else dp[ia][ib] := max(lcs(ia,ib+1),lcs(ia+1,ib));
    exit(dp[ia][ib]);
  end;

begin
  repeat
    readln(a); readln(b);
    na := length(a); nb := length(b);
    for i:=0 to na do
      for j:=0 to nb do dp[i][j] := -1;
    writeln(lcs(1,1));
  until eof;
end.
