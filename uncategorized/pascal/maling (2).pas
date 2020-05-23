const
  ep = 1e-10;
  inf = 1e50;

type
  point=record
    x,y:extended;
  end;
  segment=record
    p1,p2:point;
  end;

var
  n,i,j,k,v1,v2,a,a1,a2,z,nheap:longint;
  temp,x1,y1,x2,y2:extended;
  t1,t2,t:point;
  road:array[1..105] of segment;
  v:array[1..10005] of point;
  path:array[1..10005] of extended;
  heap,pos:array[1..10005] of longint;
  size:array[1..105] of longint;
  mem:array[1..105,1..100] of longint;
  visit:array[1..10005] of boolean;
  b:array[1..10005,1..2] of longint;

{distance between two points}
function distance(point1,point2:point):extended;
  begin
    distance:=sqrt((point1.x-point2.x)*(point1.x-point2.x)+(point1.y-point2.y)*(point1.y-point2.y));
  end;

{checks whether a point lies on a segment or not}
function onsegment(p:point; s:segment):boolean;
  begin
    onsegment:=false;
    if abs(distance(p,s.p1)+distance(p,s.p2)-distance(s.p1,s.p2))<ep then onsegment:=true;
  end;

{find the intersection point of two lines}
function intersectpoint(s1,s2:segment):point;
  var
    a1,a2,b1,b2,c1,c2,i:extended;

  begin
    if abs((s1.p1.y-s1.p2.y)*(s2.p1.x-s2.p2.x)-(s2.p1.y-s2.p2.y)*(s1.p1.x-s1.p2.x))<ep then
      with intersectpoint do
        begin
          x:=inf;
          y:=inf;
        end
    else
      begin
        a1:=s1.p2.x-s1.p1.x;
        b1:=s2.p1.x-s2.p2.x;
        c1:=s2.p1.x-s1.p1.x;
        a2:=s1.p2.y-s1.p1.y;
        b2:=s2.p1.y-s2.p2.y;
        c2:=s2.p1.y-s1.p1.y;
        i:=(c1*b2-c2*b1)/(a1*b2-a2*b1);
        //writeln(a1:0:2,' ',b1:0:2,' ',c1:0:2,' ',a2:0:2,' ',b2:0:2,' ',c2:0:2,' ',i:0:2);
        with intersectpoint do
          begin
            x:=s1.p1.x+a1*i;
            y:=s1.p1.y+a2*i;
          end;
      end;
  end;

//this function returns a vertex with smallest path from the source and update the heap table
function pop:longint;
  var
    i,p,c:longint;

  begin
    pop:=heap[1];
    i:=heap[nheap];
    dec(nheap);
    p:=1;
    repeat
      c:=p*2;
      if (c<nheap) and (path[heap[c]]>path[heap[c+1]]) then inc(c);
      if (c>nheap) or (path[i]<=path[heap[c]]) then break;
      heap[p]:=heap[c];
      pos[heap[p]]:=p;
      p:=c;
    until false;
    heap[p]:=i;
    pos[i]:=p;
  end;

//this procedure updates the heap table after a particular vertex is updated
procedure update(ps:longint);
  var
    i,p,c:longint;

  begin
    i:=heap[ps];
    c:=ps;
    repeat
      p:=c div 2;
      if (p=0) or (path[i]>=path[heap[p]]) then break;
      heap[c]:=heap[p];
      pos[heap[c]]:=c;
      c:=p;
    until false;
    heap[c]:=i;
    pos[i]:=c;
  end;

begin

  readln(n);

  for i:=1 to n do
    begin
      readln(x1,y1,x2,y2);
      t1.x:=x1; t1.y:=y1;
      t2.x:=x2; t2.y:=y2;
      road[i].p1:=t1; road[i].p2:=t2;
    end;

  k:=0;
  for i:=1 to n do
    begin
      inc(k); v[k]:=road[i].p1;
      inc(size[i]); mem[i][size[i]]:=k;
      b[k][1]:=i;
      if i=1 then v1:=k;
      
      inc(k); v[k]:=road[i].p2;
      inc(size[i]); mem[i][size[i]]:=k;
      b[k][1]:=i;
      if i=n then v2:=k;
      
      for j:=1 to i-1 do
          begin
            t:=intersectpoint(road[i],road[j]);
            if onsegment(t,road[i]) and onsegment(t,road[j]) then
              begin
                //con[i,j]:=true; con[j,i]:=true;
                inc(k); v[k]:=t; b[k][1]:=i; b[k][2]:=j;
                inc(size[i]); mem[i][size[i]]:=k;
                inc(size[j]); mem[j][size[j]]:=k;
              end;
          end;
    end;
  
//index for source = v1; index for goal = v2;
//number of vertices is k
  
//setup the heap table
  heap[1]:=v1;
  pos[v1]:=1;
  path[v1]:=0;
  nheap:=1;
  for i:=1 to k do
    if i<>v1 then
      begin
        inc(nheap);
        path[i]:=inf;
        heap[nheap]:=i;
        pos[i]:=nheap;
      end;
  fillchar(visit,sizeof(visit),false);

//this is the main algorithm - dijkstra
//the complexity is O(E log V) - O(?? log k)

  repeat
    a:=pop;
    if nheap=0 then break;
    visit[a]:=true;
    
    a1:=b[a][1]; a2:=b[a][2];
    
    if a1<>0 then
      for i:=1 to size[a1] do
        begin
          z:=mem[a1][i];
          if visit[z] then continue;
          temp:=distance(v[z],v[a]);
          if path[z]>path[a]+temp then
            begin
              path[z]:=path[a]+temp;
              update(pos[z]);
            end;
        end;
        
     if a2<>0 then
      for i:=1 to size[a2] do
        begin
          z:=mem[a2][i];
          if visit[z] then continue;
          temp:=distance(v[z],v[a]);
          if path[z]>path[a]+temp then
            begin
              path[z]:=path[a]+temp;
              update(pos[z]);
            end;
        end;
    
  until false;
{
  writeln;
  for i:=1 to n do
    begin
      for j:=1 to size[i] do write(mem[i,j],' ');
      writeln;
    end;
  writeln(v1,' ',v2);
  for i:=1 to k do writeln(i,' ',v[i].x:0:2,' ',v[i].y:0:2,':',path[i]:0:2);
}
//write the answer to stdout
  writeln(path[v2]:0:2);

end.

