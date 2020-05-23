{
ID: a_zaky01
PROG: maze1
LANG: PASCAL
}

var
  t,kasus,r0,c0,i,j,startr1,startr2,startc1,startc2,ans:longint;
  input:string;
  entrance1,entrance2:boolean;
  path:array[1..100,1..38] of integer;
  connected:array[1..100,1..38,1..4] of boolean;
  {connected[pos(r,c),dir(1:U; 2:R; 3:D; 4:L)]}

procedure dijkstra(r,c,k:integer);
  begin
    if ((path[r,c]=0) or (path[r,c]>k)) and (k<=r0*c0) then
      begin
        path[r,c]:=k;
        if c-1>0 then
          if connected[r,c,4] then dijkstra(r,c-1,k+1);
        if c+1<=c0 then
          if connected[r,c,2] then dijkstra(r,c+1,k+1);
        if r-1>0 then
          if connected[r,c,1] then dijkstra(r-1,c,k+1);
        if r+1<=r0 then
          if connected[r,c,3] then dijkstra(r+1,c,k+1);
      end;
  end;

begin
  readln(t);
  for kasus:=1 to t do
  begin
  entrance1:=false;
  entrance2:=false;
  readln(c0,r0);
  fillchar(connected,sizeof(connected),false);
  for i:=0 to r0 do
    begin
      if i>0 then
        begin
          readln(input);
          if input[1]=' ' then
            if not entrance1 then
              begin
                startr1:=i;
                startc1:=1;
                entrance1:=true;
              end
            else
              begin
                startr2:=i;
                startc2:=1;
                entrance2:=true;
              end;
          if input[2*c0+1]=' ' then
            if not entrance1 then
              begin
                startr1:=i;
                startc1:=c0;
                entrance1:=true;
              end
            else
              begin
                startr2:=i;
                startc2:=c0;
                entrance2:=true;
              end;
          for j:=1 to c0-1 do
            if input[2*j+1]=' ' then
              begin
                connected[i,j,2]:=true;
                connected[i,j+1,4]:=true;
              end;
        end;
      readln(input);
      if i=0 then
        for j:=1 to c0 do
          if input[2*j]=' ' then
            if not entrance1 then
              begin
                startr1:=1;
                startc1:=j;
                entrance1:=true;
              end
            else
              begin
                startr2:=1;
                startc2:=j;
                entrance2:=true;
              end;
      if i=r0 then
        for j:=1 to c0 do
          if input[2*j]=' ' then
            if not entrance1 then
              begin
                startr1:=r0;
                startc1:=j;
                entrance1:=true;
              end
            else
              begin
                startr2:=r0;
                startc2:=j;
                entrance2:=true;
              end;
      if not(i=0) and not(i=r0) then
        for j:=1 to c0 do
          if input[2*j]=' ' then
            begin
              connected[i,j,3]:=true;
              connected[i+1,j,1]:=true;
            end;
    end;
  fillchar(path,sizeof(path),0);
  dijkstra(startr1,startc1,1);
  dijkstra(startr2,startc2,1);
  ans:=0;
  for i:=1 to r0 do
    for j:=1 to c0 do
      if path[i,j]>ans then ans:=path[i,j];
  writeln(ans);
  end;
end.
