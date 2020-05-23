const
  maxn = 100;
  maxk = 100;
  maxq = 1000000;
  next : array[1..8,1..2] of integer
       = ((1,2),(2,1),(-1,2),(2,-1),(1,-2),(-2,1),(-1,-2),(-2,-1));

var
  x,y,n,k,i,j,nextx,nexty,nextk:integer;
  qtake,qsave:longint;
  queue:array[1..maxq,1..3] of integer;
  flag:array[1..maxn,1..maxn,1..maxk] of boolean;

begin
  readln(x,y,n,k);
  fillchar(flag,sizeof(flag),false);
  qtake:=1;
  qsave:=1;
  queue[1][1]:=x; queue[1][2]:=y;
  queue[1][3]:=0;
  while qtake<=qsave do
    begin
      nextk:=queue[qtake][3]+1;
      for i:=1 to 8 do
        begin
          if nextk>k then break;
          nextx:=queue[qtake][1]+next[i][1];
          nexty:=queue[qtake][2]+next[i][2];
          if (nextx<1) or (nexty<1) or (nextx>n) or (nexty>n) then continue;
          if flag[nextx][nexty][nextk] then continue;
          inc(qsave);
          queue[qsave][1]:=nextx;
          queue[qsave][2]:=nexty;
          queue[qsave][3]:=nextk;
          flag[nextx][nexty][nextk]:=true;
        end;
      inc(qtake);
    end;
  for i:=1 to n do
    for j:=1 to n do
      if flag[i][j][k] then writeln(i,' ',j);
end.

