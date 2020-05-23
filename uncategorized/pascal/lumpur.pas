type
  coor=record
    x,y:integer;
  end;

const
  limit=252004 shl 1;

var
  t,kasus,i,n,tx,ty,qtake,qsave:longint;
  min,max,st:coor;
  queue:array[1..limit] of coor;
  path:array[-501..501,-501..501] of integer;
  obs,wait:array[-501..501,-501..501] of boolean;

procedure dijkstra(p:coor);
  procedure check(tx,ty:integer);
    begin
      if not obs[tx,ty] then
        if (path[tx,ty]<0) or (path[tx,ty]>path[p.x,p.y]+1) then
          begin
            path[tx,ty]:=path[p.x,p.y]+1;
            if not wait[tx,ty] then
              begin
                qsave:=(qsave mod limit)+1;
                with queue[qsave] do
                  begin
                    x:=tx;
                    y:=ty;
                  end;
                wait[tx,ty]:=true;
              end;
          end;
    end;

  begin
    wait[p.x,p.y]:=false;
    if p.x-1>=min.x then check(p.x-1,p.y);
    if p.x+1<=max.x then check(p.x+1,p.y);
    if p.y-1>=min.y then check(p.x,p.y-1);
    if p.y+1<=max.y then check(p.x,p.y+1);
    if qtake<>qsave then
      begin
        qtake:=(qtake mod limit)+1;
        dijkstra(queue[qtake]);
      end;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      fillchar(obs,sizeof(obs),false);
      fillchar(obs,sizeof(wait),false);
      fillchar(path,sizeof(path),255);
      with min do
        begin
          x:=0;
          y:=0;
        end;
      with max do
        begin
          x:=0;
          y:=0;
        end;
      readln(st.x,st.y,n);
      if min.x>st.x then min.x:=st.x;
      if min.y>st.y then min.y:=st.y;
      if max.x<st.x then max.x:=st.x;
      if max.y<st.y then max.y:=st.y;
      for i:=1 to n do
        begin
          readln(tx,ty);
          obs[tx,ty]:=true;
          if min.x>tx then min.x:=tx;
          if min.y>ty then min.y:=ty;
          if max.x<tx then max.x:=tx;
          if max.y<ty then max.y:=ty;
        end;
      dec(min.x);
      dec(min.y);
      inc(max.x);
      inc(max.y);
      qtake:=0;
      qsave:=0;
      path[st.x,st.y]:=0;
      dijkstra(st);
      writeln(path[0,0]);
    end;
end.
