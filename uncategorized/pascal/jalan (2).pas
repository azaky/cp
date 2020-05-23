type
  point=record
          x,y:longint;
        end;

var
  t,kasus,n,m,i,j,size,a,b,k:integer;
  best,path:extended;
  p:array[1..1000] of point;
  stat:array[1..1000] of boolean;
  c:array[1..1000,1..1000] of boolean;
  min:array[1..1000] of extended;

function d(a,b:integer):extended;
  begin
    d:=sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y));
  end;

procedure fill(k:integer);
  var
    i:integer;

  begin
    stat[k]:=true;
    inc(size);
    for i:=1 to n do
      if not stat[i] and c[i,k] then fill(i)
        else if d(i,k)<min[i] then min[i]:=d(i,k);
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      fillchar(stat,sizeof(stat),false);
      fillchar(c,sizeof(c),false);
      readln(n,m);
      for i:=1 to n do readln(p[i].x,p[i].y);
      for i:=1 to m do
        begin
          readln(a,b);
          c[a,b]:=true;
          c[b,a]:=true;
        end;
      for i:=1 to n do min[i]:=d(i,1);
      size:=0;
      path:=0;
      fill(1);
      while true do
        begin
          best:=-1.00;
          for i:=1 to n do
            if not stat[i] and ((best<0) or (best>min[i])) then
              begin
                k:=i;
                best:=min[i];
              end;
          if best<0 then break;
          path:=path+best;
          fill(k);
        end;
      writeln(path:0:2);
    end;
end.

