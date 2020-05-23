const
  maxv = 1000; //maximum number of vertices
  maxe = 50000; //maximum number of edges

var
  n,m,a,b,v1,v2,v,nheap,i,t,s,f:longint;
  ans:int64;
  visit,fin:array[1..maxv+5] of boolean;
  w,ep1,ep2:array[1..maxe+5] of longint;
  deg,heap,pos,st:array[1..maxv+5] of longint;
  z,d:array[1..maxe*2+5] of longint;
  path:array[1..maxv+5] of int64;

//this function returns a vertex with smallest path from the source and update the heap table
function pop:longint;
  var
    i,p,c:longint;

  begin
    pop:=heap[1];
    i:=heap[nheap]; dec(nheap); p:=1;
    repeat
      c:=p*2;
      if (c<nheap) and (path[heap[c]]>path[heap[c+1]]) then inc(c);
      if (c>nheap) or (path[i]<=path[heap[c]]) then break;
      heap[p]:=heap[c]; pos[heap[p]]:=p; p:=c;
    until false;
    heap[p]:=i; pos[i]:=p;
  end;

//this procedure updates the heap table after a particular vertex is updated
procedure update(ps:longint);
  var
    i,p,c:longint;

  begin
    i:=heap[ps]; c:=ps;
    repeat
      p:=c div 2;
      if (p=0) or (path[i]>=path[heap[p]]) then break;
      heap[c]:=heap[p]; pos[heap[c]]:=c; c:=p;
    until false;
    heap[c]:=i; pos[i]:=c;
  end;

begin
//n=number of vertices; m=number of edges
  readln(n,m,s,f);
  for i:=1 to s do read(st[i]);
  for i:=1 to f do
    begin
      read(a); fin[a]:=true;
    end;

//reading information about the edges - its weight and what vertex is connected to it
  for i:=1 to m do
    begin
      readln(a,b,w[i]);
      inc(deg[a]); inc(deg[b]);
      ep1[i]:=a; ep2[i]:=b;
    end;

//save the properties of vertex v1 - its neighbor and weights of the edges that is connected -
//in indices deg[v1]+1 to deg[v1+1] of array z
  for i:=2 to n+1 do deg[i]:=deg[i]+deg[i-1];
  for i:=1 to m do
    begin
      v1:=ep1[i]; v2:=ep2[i];
      z[deg[v1]]:=v2; z[deg[v2]]:=v1;
      d[deg[v1]]:=w[i]; d[deg[v2]]:=w[i];
      dec(deg[v1]); dec(deg[v2]);
    end;
  
  ans:=maxlongint;
  
  for t:=1 to s do begin
  v1:=st[t];

//setup the heap table
  heap[1]:=v1; pos[v1]:=1; nheap:=1;
  path[v1]:=0; 
  for i:=1 to n do
    if i<>v1 then
      begin
        inc(nheap); heap[nheap]:=i; pos[i]:=nheap;
        path[i]:=maxlongint;
      end;
  fillchar(visit,sizeof(visit),false);

//this is the main algorithm - dijkstra 
//the complexity is O(E log V) - O(m log n)
  repeat
    a:=pop;
    if fin[a] then
      begin
        if path[a]<ans then ans:=path[a];
        break;
      end;
    if path[a]>=ans then break;
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
  
  end;

//write the answer to stdout
  writeln(ans);

end.

