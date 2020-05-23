var
  kasus,n,i,j,t,x,y:longint;
  a,sum:array[0..11,0..11] of longint;
  ans:array[0..11] of longint;

function getsum(x,y:longint):longint;
  begin
    exit(sum[y][y]+sum[x-1][x-1]-sum[y][x-1]-sum[x-1][y]);
  end;

begin
  repeat
    inc(kasus);
    readln(n); if n=0 then break;
    for i:=1 to n do
      for j:=1 to n do read(a[i][j]);
    fillchar(sum,sizeof(sum),0);
    for i:=1 to n do
      for j:=1 to n do sum[i][j] := sum[i-1][j] + sum[i][j-1] + a[i][j] - sum[i-1][j-1];
    t := (n+1) div 2;
    x := (n+1) div 2; y := (n+2) div 2;
    ans[t] := getsum(x,y); ans[t+1] := 0;
    for i:=t-1 downto 1 do
      begin
        dec(x); inc(y);
        ans[i] := getsum(x,y);
      end;
    write('Case ',kasus,':');
    for i:=1 to t do write(' ',ans[i]-ans[i+1]);
    writeln;
  until false;
end.
