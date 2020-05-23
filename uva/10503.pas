type d=record l,r:longint; end;

var
  n,m,i:longint;
  x,y:d;
  a:array[0..111] of d;
  visit,dp:array[0..1 shl 15,0..7] of boolean;

function domino(ll,s,n:longint):boolean;
  var
    i:longint;
  
  begin
    if n=0 then exit(ll=y.l);
    if visit[s][ll] then exit(dp[s][ll]);
    visit[s][ll] := true;
    dp[s][ll]:=false;
    for i:=1 to m do
      if s and (1 shl (i-1))>0 then
        begin
          if a[i].l=ll then
            begin
              dp[s][ll] := dp[s][ll] or domino(a[i].r,s xor (1 shl (i-1)),n-1);
              if dp[s][ll] then exit(true);
            end;
          if a[i].r=ll then
            begin
              dp[s][ll] := dp[s][ll] or domino(a[i].l,s xor (1 shl (i-1)),n-1);
              if dp[s][ll] then exit(true);
            end;
        end;
    exit(false);
  end;

begin
  repeat
    readln(n); if n=0 then break;
    readln(m);
    readln(x.l,x.r);
    readln(y.l,y.r);
    for i:=1 to m do readln(a[i].l,a[i].r);
    fillchar(visit,sizeof(visit),false);
    if domino(x.r,(1 shl m)-1,n) then writeln('YES') else writeln('NO');
  until false;
end.
