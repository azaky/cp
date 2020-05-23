uses math;

const
  left:longint = 1;
  right:longint = 2;
  inf = 10000000;

var
  n,k,i,j,ansl,ansr:longint;
  s:array[1..2] of ansistring;
  dp:array[1..2,0..211111] of longint;
  v:array[1..2,0..211111] of boolean;

function next(x:longint):longint;
  begin
    if x=1 then exit(2) else exit(1);
  end;

procedure return;
  begin
{
    writeln(i);
  for i:=1 to 2 do
    begin
      for j:=1 to n+k do write(dp[i][j]:12);writeln;
    end;
}
    writeln('YES'); halt;
  end;

function jump(wall,h:longint):longint;
  begin
    if (h<1) or (h>n+k) then exit(inf);
    if s[wall][h]='X' then exit(inf);
    if v[wall,h] then exit(dp[wall][h]);
    v[wall,h] := true;
    if h>n then
      begin
        if h=n+1 then dp[wall][h] := jump(wall,h-1);
        dp[wall][h] := min(dp[wall][h],jump(next(wall),h-k));
        if dp[wall][h] >= h then dp[wall][h] := inf else return;
        exit(dp[wall][h]);
      end;
    dp[wall][h] := min(min(jump(wall,h+1),jump(wall,h-1)),jump(next(wall),h-k));
    if dp[wall][h]+1 >= h then dp[wall][h] := inf else inc(dp[wall][h]);
    exit(dp[wall][h]);
  end;

begin
  readln(n,k);
  readln(s[1]);readln(s[2]);
  for i:=1 to k do
    begin
      s[1] := s[1] + '-';
      s[2] := s[2] + '-';
    end;
  //writeln(s[1]);writeln(s[2]);
  for i:=1 to n+k do begin dp[1][i]:=inf; dp[2][i]:=inf; end;
  dp[1][1] := 0; v[1][1] := true;
  for i:=n+1 to n+k do
    begin
      if jump(left,i)<i then return;
      if jump(right,i)<i then return;
    end;
  writeln('NO'); halt;
  ansl := jump(left,n); ansr := jump(right,n);
  for i:=1 to 2 do
    begin
      for j:=1 to n do write(dp[i][j]:12);writeln;
    end;
  if min(ansl,ansr)<n then writeln('YES') else writeln('NO');
end.
