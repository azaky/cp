type
  num=-501..501;
  coor=record
         x,y:num;
         k:longint;
       end;

var
  t,kasus,i,n,x0,y0,x1,y1,maxx,maxy,minx,miny,qsave,qtake:longint;
  ini:coor;
  queue:array[1..700000] of coor;
  obs,stat:array[-501..501,-501..501] of boolean;

procedure search(ini:coor);
  begin
    stat[ini.x,ini.y]:=true;
    if (ini.x=x0) and (ini.y=y0) then
      begin
        writeln(ini.k);
        exit;
      end
    else
      begin
        if not obs[ini.x-1,ini.y] and not stat[ini.x-1,ini.y] and (ini.x>=minx) then
          begin
            inc(qsave);
            with queue[qsave] do
              begin
                x:=ini.x-1;
                y:=ini.y;
                k:=ini.k+1;
              end;
          end;
        if not obs[ini.x+1,ini.y] and not stat[ini.x+1,ini.y] and (ini.x<=maxx) then
          begin
            inc(qsave);
            with queue[qsave] do
              begin
                x:=ini.x+1;
                y:=ini.y;
                k:=ini.k+1;
              end;
          end;
        if not obs[ini.x,ini.y-1] and not stat[ini.x,ini.y-1] and (ini.y>=miny) then
          begin
            inc(qsave);
            with queue[qsave] do
              begin
                x:=ini.x;
                y:=ini.y-1;
                k:=ini.k+1;
              end;
          end;
        if not obs[ini.x,ini.y+1] and not stat[ini.x,ini.y+1] and (ini.y<=maxy) then
          begin
            inc(qsave);
            with queue[qsave] do
              begin
                x:=ini.x;
                y:=ini.y+1;
                k:=ini.k+1;
              end;
          end;
      end;
    if qtake<=qsave then
      begin
        inc(qtake);
        search(queue[qtake]);
      end;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      fillchar(stat,sizeof(stat),false);
      fillchar(obs,sizeof(obs),false);
      readln(x0,y0,n);
      minx:=x0;
      miny:=y0;
      maxx:=x0;
      maxy:=y0;
      for i:=1 to n do
        begin
          readln(x1,y1);
          obs[x1,y1]:=true;
          if minx>x1 then minx:=x1;
          if miny>y1 then miny:=y1;
          if maxx<x1 then maxx:=x1;
          if maxy<y1 then maxy:=y1;
        end;
      with ini do
        begin
          x:=0;
          y:=0;
          k:=0;
        end;
      qtake:=0;
      qsave:=0;
      search(ini);
    end;
end.
