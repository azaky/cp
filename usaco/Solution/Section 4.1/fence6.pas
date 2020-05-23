{
ID: a_zaky01
PROG: fence6
LANG: PASCAL
}

type
  arr=array[1..9] of integer;

var
  i,s,n,numv,k,j,count,temps,tempv,ans:longint;
  used,stat:array[1..100] of boolean;
  len,adj,num,path:array[1..100] of longint;
  q:array[1..2] of integer;
  neg,dis:array[1..100,1..100] of integer;
  con:array[1..100,1..100] of boolean;
  fen:array[1..100] of arr;
  temp:arr;
  fin,fout:text;

procedure addvertex(temp:arr; count:integer);
  var
    i:integer;

  begin
    for i:=1 to count do
      if used[temp[i]] then exit;
    inc(numv);
    fen[numv]:=temp;
    num[numv]:=count;
  end;

function connected(a,b:integer):integer;
  var
    ia,ib:integer;

  begin
    connected:=0;
    for ia:=1 to num[a] do
      for ib:=1 to num[b] do
        if fen[a][ia]=fen[b][ib] then exit(fen[a][ia]);
  end;

procedure dijkstra(v:integer);
  var
    i,min,next:integer;

  begin
    stat[v]:=true;
    for i:=1 to adj[v] do
      if con[v,neg[v][i]] then
        if (path[neg[v][i]]<0) or (path[v]+dis[v,neg[v][i]]<path[neg[v][i]]) then
          path[neg[v][i]]:=path[v]+dis[v,neg[v][i]];
    min:=-1;
    next:=0;
    for i:=1 to numv do
      if not stat[i] then
        if ((min<0) or (path[i]<min)) and (path[i]>0) then
          begin
            next:=i;
            min:=path[i];
          end;
    if next>0 then dijkstra(next);
  end;

begin
  assign(fin,'fence6.in');
  assign(fout,'fence6.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  numv:=0;
  for i:=1 to n do
    begin
      readln(fin,s,len[s],q[1],q[2]);
      for k:=1 to 2 do
        begin
          count:=1;
          temp[1]:=s;
          for j:=1 to q[k] do
            begin
              inc(count);
              read(fin,temp[count]);
            end;
          addvertex(temp,count);
        end;
      used[s]:=true;
    end;
  for i:=1 to numv-1 do
    for j:=i+1 to numv do
      begin
        temps:=connected(i,j);
        if temps>0 then
          begin
            inc(adj[i]);
            inc(adj[j]);
            neg[i][adj[i]]:=j;
            neg[j][adj[j]]:=i;
            dis[i,j]:=len[temps];
            dis[j,i]:=len[temps];
            con[i,j]:=true;
            con[j,i]:=true;
          end;
      end;
  ans:=25501;
  for k:=numv downto 1 do
    if adj[k]>1 then
      for i:=1 to adj[k] do
        begin
          tempv:=neg[k][i];
          con[k,tempv]:=false;
          con[tempv,k]:=false;
          fillchar(path,sizeof(path),255);
          fillchar(stat,sizeof(stat),false);
          path[k]:=0;
          dijkstra(k);
          if path[tempv]>0 then
            if path[tempv]+dis[k,tempv]<ans then ans:=path[tempv]+dis[k,tempv];
          con[k,tempv]:=true;
          con[tempv,k]:=true;
        end;
  writeln(fout,ans);
  close(fin);
  close(fout);
end.
