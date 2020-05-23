const
  maxv = 100000; //maximum number of vertices
  maxe = 200000; //maximum number of edges

var
  n,m,a,b,v1,v2,v,nheap,i:longint;
  visit:array[1..maxv+5] of boolean;
  w,ep1,ep2:array[1..maxe+5] of longint;
  deg,heap,pos:array[1..maxv+5] of longint;
  z,d:array[1..maxe*2+5] of longint;
  path:array[1..maxv+5] of int64;
  
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
  end;

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

  readln(n,m); //n=number of vertices; m=number of edges

  for i:=1 to m do
    begin
      readln(a,b,w[i]); //describe about i-th edge - it connects vertices a and b, and has weight of w
      inc(deg[a]); //increase degree of vertex a
      inc(deg[b]); //increase degree of vertex b
      ep1[i]:=a; //first endpoint of i-th edge i.e. vertex a
      ep2[i]:=b; //second endpoint of i-th edge i.e. vertex b
    end;

  for i:=2 to n+1 do deg[i]:=deg[i]+deg[i-1];

  for i:=1 to m do
    begin
      v1:=ep1[i];
      v2:=ep2[i];
      z[deg[v1]]:=v2;
      z[deg[v2]]:=v1;
      d[deg[v1]]:=w[i];
      d[deg[v2]]:=w[i];
      dec(deg[v1]);
      dec(deg[v2]);
    end;
  //shortly, the code above save the properties of vertex v1 - its neighbor and weights of the edges that connected to it -
  //in indices deg[v1]+1 to deg[v1+1]

  readln(v1,v2); //this is the start and goal vertices

  //setup the heap table
  heap[1]:=v1;
  pos[v1]:=1;
  path[v1]:=0;
  nheap:=1;
  for i:=1 to n do
    if i<>v1 then
      begin
        inc(nheap);
        path[i]:=maxlongint;
        heap[nheap]:=i;
        pos[i]:=nheap;
      end;
  fillchar(visit,sizeof(visit),false);

  //this is the main algorithm - dijkstra
  repeat
    a:=pop;
    if nheap=0 then break;
    visit[a]:=true;

    for i:=deg[a]+1 to deg[a+1] do
      begin
        v:=z[i];
        if visit[v] then continue;
        if path[v]>path[a]+d[i] then
          begin
            path[v]:=path[a]+d[i];
            update(pos[v]);
          end;
      end;
  until false;

  writeln(path[v2]);

end.

