var
  n,m,i,x,p,t:longint;
  a:array[1..1000] of longint;
  used:array[1..200000] of boolean;
  dp,visit:array[0..1001,0..2003] of boolean;
 
function run(t,pos:longint):boolean;
  begin
    if (pos=0) or (pos>n) then exit(false);
    if visit[t,pos] then exit(dp[t,pos])
      else visit[t,pos]:=true;
    if a[t]=pos then exit(false);
    if t>m then exit(true);
    if run(t+1,pos+1) then
      begin
        dp[t,pos]:=true;
        exit(true);
      end;
    if run(t+1,pos-1) then
      begin
        dp[t,pos]:=true;
        exit(true);
      end;
    exit(false);
  end;
 
begin
  readln(n,m);
  for i:=1 to m do readln(a[i]);
  //subtask 4
  if n>2002 then
    begin
      for i:=1 to m do used[a[i]]:=true;
      for i:=1 to n-1 do
        if not (used[i] or used[i+1]) then break;
      x:=i;
      for i:=1 to m do
        if i mod 2=1 then writeln(x)
          else writeln(x+1);
      halt;
    end;
  //other subtask
  //let run(m,n) denotes whether it is possible to run away from Ganesh if at time m, the special duck was in the n-th cage
  fillchar(dp,sizeof(dp),false);
  fillchar(visit,sizeof(visit),false);
  for i:=1 to n do
    if run(1,i) then
      begin
        p:=i; writeln(p);
        for t:=2 to m do
          begin
            if run(t,p+1) then inc(p) else dec(p);
            writeln(p);
          end;
        halt;
      end;
  writeln('menyerah');
end.
