{
ID: a_zaky01
PROG: cornmaze
LANG: PASCAL
}

type
  coor = array[1..2] of integer;

const
  maxn = 300;
  maxq = 90005;
  next : array[1..4] of coor = ((1,0),(-1,0),(0,1),(0,-1));
  
var
  n,m,i,j,qtake,qsave,pnow:longint;
  ch:char;
  st,now,nc:coor;
  t:array[1..maxn,1..maxn] of char;
  go:array[1..maxn,1..maxn] of coor;
  temp:array['A'..'Z'] of coor;
  q:array[1..maxq] of coor;
  path:array[1..maxn,1..maxn] of longint;
  check:array['A'..'Z'] of boolean;
  visit:array[1..maxn,1..maxn] of boolean;

begin
  assign(input,'cornmaze.in'); reset(input);
  assign(output,'cornmaze.out'); rewrite(output);
  
  fillchar(check,sizeof(check),false);
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(ch); t[i,j]:=ch;
          if ch='@' then
            begin
              st[1]:=i;
              st[2]:=j;
            end;
        end;
      readln;
    end;
  
  for i:=1 to n do
    for j:=1 to m do
      if t[i,j]='#' then continue
        else if (t[i,j]='.') or (t[i,j]='=') or (t[i,j]='@') then
          begin
            go[i,j,1]:=i;
            go[i,j,2]:=j;
          end
        else if not check[t[i,j]] then
          begin
            check[t[i,j]]:=true;
            temp[t[i,j],1]:=i;
            temp[t[i,j],2]:=j;
          end
        else
          begin
            go[i,j]:=temp[t[i,j]];
            go[temp[t[i,j],1],temp[t[i,j],2],1]:=i;
            go[temp[t[i,j],1],temp[t[i,j],2],2]:=j;
          end;
  
  qtake:=1; qsave:=1;
  q[1]:=st; path[st[1],st[2]]:=0;
  
  repeat
    visit[q[qtake,1],q[qtake,2]]:=true;
    now:=q[qtake]; //writeln(now[1],' ',now[2]);
    if t[now[1],now[2]]='=' then
      begin
        writeln(path[now[1],now[2]]);
        break;
      end;
    for i:=1 to 4 do
      begin
        nc:=go[now[1]+next[i,1],now[2]+next[i,2]];
        pnow:=path[q[qtake,1],q[qtake,2]]+1;
        if t[nc[1],nc[2]]='#' then continue;
        if visit[nc[1],nc[2]] then continue;
        if (path[nc[1],nc[2]]>0) and (path[nc[1],nc[2]]<pnow) then continue;
        inc(qsave);
        q[qsave]:=nc;
        path[nc[1],nc[2]]:=pnow;
      end;
    inc(qtake);
  until qtake>qsave;
  
  close(input);
  close(output);
end.
