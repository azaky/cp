{
ID: a_zaky01
PROG: camelot
LANG: PASCAL
}

uses
  math;

type
  coor=record
    r,c:integer;
  end;

var
  r0,c0,n,i,j,r1,c1,r2,c2,qsave,qtake:integer;
  ans:longint;
  ch:char;
  temp:coor;
  p,queue:array[0..780] of coor;
  best:array[1..26,1..30,1..26,1..30] of integer;
  total:array[1..26,1..30] of longint;
  path:array[0..780] of integer;
  stat:array[1..26,1..30] of boolean;
  fin,fout:text;

procedure bfs(ini:coor);
  procedure add(rn,cn:integer);
    var
      temp:coor;

    begin
      if not stat[rn,cn] then
        begin
          stat[rn][cn]:=true;
          inc(qsave);
          temp.r:=rn;
          temp.c:=cn;
          path[qsave]:=path[qtake]+1;
          queue[qsave]:=temp;
        end;
    end;

  begin
    best[r1][c1][ini.r][ini.c]:=path[qtake];
    if ini.r-2>0 then
      begin
        if ini.c-1>0 then add(ini.r-2,ini.c-1);
        if ini.c+1<=c0 then add(ini.r-2,ini.c+1);
      end;
    if ini.r+2<=r0 then
      begin
        if ini.c-1>0 then add(ini.r+2,ini.c-1);
        if ini.c+1<=c0 then add(ini.r+2,ini.c+1);
      end;
    if ini.r-1>0 then
      begin
        if ini.c-2>0 then add(ini.r-1,ini.c-2);
        if ini.c+2<=c0 then add(ini.r-1,ini.c+2);
      end;
    if ini.r+1<=r0 then
      begin
        if ini.c-2>0 then add(ini.r+1,ini.c-2);
        if ini.c+2<=c0 then add(ini.r+1,ini.c+2);
      end;
    if qtake<qsave then
      begin
        inc(qtake);
        bfs(queue[qtake]);
      end;
  end;

begin
  assign(fin,'camelot.in');
  assign(fout,'camelot.out');
  reset(fin);
  rewrite(fout);
  readln(fin,c0,r0);
  n:=-1;
  while not eof(fin) do
    begin
      inc(n);
      repeat
        read(fin,ch);
        if eof(fin) then
          begin
            dec(n);
            break;
          end;
      until (ord(ch)>64) and (ord(ch)<91);
      if eof(fin) then break;
      read(fin,p[n].c);
      p[n].r:=ord(ch)-64;
    end;
  for r1:=1 to r0 do
    for c1:=1 to c0 do
      begin
        fillchar(best[r1][c1],sizeof(best[r1][c1]),255);
        fillchar(stat,sizeof(stat),false);
        fillchar(path,sizeof(path),0);
        qsave:=0;
        qtake:=0;
        temp.r:=r1;
        temp.c:=c1;
        stat[r1][c1]:=true;
        bfs(temp);
      end;
  for r1:=1 to r0 do
    for c1:=1 to c0 do
      begin
        total[r1][c1]:=0;
        for i:=1 to n do
          if best[r1][c1][p[i].r][p[i].c]<0 then
            begin
              total[r1][c1]:=-1;
              break;
            end
          else inc(total[r1][c1],best[r1][c1][p[i].r][p[i].c]);
      end;
  ans:=-1;
  for r1:=1 to r0 do
    for c1:=1 to c0 do
      if total[r1][c1]>=0 then
        for r2:=p[0].r-2 to p[0].r+2 do
          for c2:=p[0].c-2 to p[0].c+2 do
            if (r2>0) and (r2<=r0) and (c2>0) and (c2<=c0) then
              if best[r1][c1][r2][c2]>=0 then
                for i:=1 to n do
                  if best[r2][c2][p[i].r][p[i].c]>=0 then
                    if (ans<0) or (total[r1][c1]-best[r1][c1][p[i].r][p[i].c]+best[r1][c1][r2][c2]+best[r2][c2][p[i].r][p[i].c]+max(abs(p[0].r-r2),abs(p[0].c-c2))<ans) then
                      ans:=total[r1][c1]-best[r1][c1][p[i].r][p[i].c]+best[r1][c1][r2][c2]+best[r2][c2][p[i].r][p[i].c]+max(abs(p[0].r-r2),abs(p[0].c-c2));
  if n=0 then writeln(fout,0)
    else writeln(fout,ans);
  close(fin);
  close(fout);
end.
