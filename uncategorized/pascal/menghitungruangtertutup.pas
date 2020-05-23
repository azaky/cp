const
  map:array[1..3,1..3,1..3] of integer = (((0,0,0),
                                           (0,0,0),
                                           (0,0,0)),
                                          ((0,0,1),
                                           (0,1,0),
                                          (1,0,0)),
                                          ((1,0,0),
                                           (0,1,0),
                                           (0,0,1)));
  dontknow = './\';
  
var
  n,m,i,j,room,i1,j1,p:longint;
  ch:char;
  meetedge:boolean;
  obs,visit:array[0..751,0..751] of boolean;

procedure fill(i,j:longint);
  begin
    if (i=0) or (i>3*n) or (j=0) or (j>3*m) then
      begin
        meetedge:=true;
        exit;
      end
    else if visit[i,j] or obs[i,j] then exit
      else visit[i,j]:=true;
    fill(i+1,j);
    fill(i-1,j);
    fill(i,j+1);
    fill(i,j-1);
  end;

begin
  readln(n,m);
  for i:=1 to n do
    for j:=1 to m do
      begin
        read(ch); p:=pos(ch,dontknow);
        for i1:=1 to 3 do
          for j1:=1 to 3 do
            obs[3*i-3+i1,3*j-3+j1]:=map[p,i1,j1]=1;
        if j=m then readln;
      end;
  fillchar(visit,sizeof(visit),false);
  room:=0;
  for i:=1 to 3*n do
    for j:=1 to 3*m do
      begin
        //if obs[i,j] then write('#') else write('.'); if j=3*m then writeln;
        if visit[i,j] or obs[i,j] then continue else meetedge:=false;
        fill(i,j); if not meetedge then inc(room);
      end;
  writeln(room);
end.

