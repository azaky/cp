uses math;

type
  point=record
    x,y:extended;
  end;
  segment=record
    p1,p2:point;
  end;

const
  ep = 1e-11; eps = ep;
  inf = 1e4000;
  o : point = (x:0; y:0);
  
function create(x,y:extended):point;
  var
    res:point;
  begin
    res.x := x; res.y := y;
    exit(res);
  end;
  
//returns the z-component of cross product of two vectors
//if the z-component is positive, then these two vectors form a left turn
//otherwise a right turn
function cross(p1,p2:point):extended;
  begin
    exit(p1.x*p2.y-p1.y*p2.x);
  end;

//returns a boolean value that shows three points form a right turn or not
function right(p1,p2,p3:point):boolean;
  begin
    //exit(cross(p2-p1,p3-p2)<=0);
    exit(cross(create(p2.x-p1.x,p2.y-p1.y),create(p3.x-p2.x,p3.y-p2.y))<0);
  end;
  
var
  n,i,j,p1,index:longint;
  p:array[0..5000] of point;
  deg,idx,next,z,ep1,ep2,c,root,size:array[0..5000] of longint;
  used:array[0..5000] of boolean;

procedure traverse(r,v:longint);
  var
    i:longint;
  
  begin
    inc(index); idx[v] := index; root[v] := r;
    for i:=deg[v]+1 to deg[v+1] do
      if z[i]<>r then traverse(v,z[i]);
    size[v] := index - idx[v];
  end;

procedure color(v,ip:longint);
  var
    i,j,next:longint;
  
  begin
    //writeln(v,' ',ip);
    c[ip] := v; used[ip] := true;
    for i:=deg[v]+1 to deg[v+1] do
      begin
        if z[i]=root[v] then continue;
        for j:=1 to n do
          if not used[j] then break;
        next := j;
        for j:=next+1 to n do
          if not used[j] then
            if right(p[j],p[ip],p[next]) then next := j;
        color(z[i],next);
      end;
  end;

begin
  readln(n);
  for i:=1 to n-1 do
    begin
      readln(ep1[i],ep2[i]);
      inc(deg[ep1[i]]); inc(deg[ep2[i]]);
    end;
  for i:=1 to n+1 do deg[i] := deg[i]+deg[i-1];
  for i:=1 to n-1 do
    begin
      z[deg[ep1[i]]] := ep2[i];
      z[deg[ep2[i]]] := ep1[i];
      dec(deg[ep1[i]]); dec(deg[ep2[i]]);
    end;
  for i:=1 to n do readln(p[i].x,p[i].y);
  p1 := 1;
  for i:=2 to n do
    if (p[i].x<p[p1].x) or ((p[i].x=p[p1].x) and (p[i].y<p[p1].y)) then p1 := i;
  fillchar(root,sizeof(root),255);
  traverse(0,1);
  color(1,p1);
  for i:=1 to n-1 do write(c[i],' ');writeln(c[n]);
end.
