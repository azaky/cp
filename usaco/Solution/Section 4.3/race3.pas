{
ID: a_zaky01
PROG: race3
LANG: PASCAL
}

var
  n,v,c,i,ans1,ans2:integer;
  deg:array[0..50] of integer;
  adj:array[0..50,1..51] of integer;
  visit,visit2:array[0..50] of boolean;
  unavoid,split:array[1..49] of boolean;
  fin,fout:text;

procedure fill(v:integer);
  var
    i:integer;

  begin
    if (v=c) or visit[v] then exit;
    visit[v]:=true;
    for i:=1 to deg[v] do
      if not visit[adj[v,i]] then fill(adj[v,i]);
  end;

procedure fill2(v:integer);
  var
    i:integer;

  begin
    if visit[v] then
      begin
        split[c]:=false;
        exit;
      end;
    if visit2[v] or not split[c] then exit;
    visit2[v]:=true;
    for i:=1 to deg[v] do fill2(adj[v,i]);
  end;

begin
  assign(fin,'race3.in');
  assign(fout,'race3.out');
  reset(fin);
  rewrite(fout);
  n:=0;
  while true do
    begin
      repeat
        read(fin,v);
        if v<0 then break;
        inc(deg[n]);
        adj[n,deg[n]]:=v;
      until false;
      if v=-1 then break;
      inc(n);
    end;
  dec(n);
  for c:=1 to n-1 do
    begin
      fillchar(visit,sizeof(visit),false);
      fill(0);
      if not visit[n] then
        begin
          inc(ans1);
          unavoid[c]:=true;
          split[c]:=true;
          fillchar(visit2,sizeof(visit2),false);
          fill2(c);
          if split[c] then inc(ans2);
        end;
    end;
  write(fout,ans1);
  for i:=1 to n-1 do
    if unavoid[i] then write(fout,' ',i);
  writeln(fout);
  write(fout,ans2);
  for i:=1 to n-1 do
    if split[i] then write(fout,' ',i);
  writeln(fout);
  close(fin);
  close(fout);
end.
