const
  infinite = round(1e18);
  maxn = 100005*2;
  maxm = 200005*2;

var
  n,m,i,j,v,u,nheap:longint;
  x,ans:int64;
  deg,road,heap,pos:array[0..maxn] of longint;
  intree:array[0..maxn] of boolean;
  a,b:array[0..maxm] of longint;
  c:array[0..maxm] of int64;
  used:array[0..maxm] of boolean;
  z,h:array[0..2*maxm] of longint;
  dis:array[0..maxn] of int64;
{
procedure swap(var a,b:longint);
  var
    temp:longint;

  begin
    temp:=a; a:=b; b:=temp;
  end;

function pop:longint;
  var
    p,c:longint;
  
  begin
    pop:=heap[1];
	dec(nheap); heap[1]:=heap[nheap+1]; pos[heap[1]]:=1;
	p:=1;
	repeat
	  c:=2*p;
	  if c>nheap then break;
	  if dis[heap[p]]<=dis[heap[c]] then break;
	  if (c+1<=nheap) and (dis[heap[c+1]]<dis[heap[p]]) then inc(c);
	  swap(pos[heap[c]],pos[heap[p]]);
	  swap(heap[c],heap[p]);
	  p:=c;
	until false;
  end;

procedure update(v:longint);
  var
    p,c:longint;
  
  begin
    p:=pos[v];
    repeat
	  c:=p div 2;
	  if (c=0) or (dis[heap[c]]<=dis[heap[p]]) then break;
	  swap(pos[heap[c]],pos[heap[p]]);
	  swap(heap[c],heap[p]);
	  p:=c;
	until false;
  end;

procedure push(v:longint);
  begin
    inc(nheap);
	heap[nheap]:=v; pos[v]:=nheap;
	update(v);
  end;
}

function pop:longint;
  var
    i,p,c:longint;

  begin
    pop:=heap[1];
    i:=heap[nheap]; dec(nheap); p:=1;
    repeat
      c:=p*2;
      if (c<nheap) and (dis[heap[c]]>dis[heap[c+1]]) then inc(c);
      if (c>nheap) or (dis[i]<=dis[heap[c]]) then break;
      heap[p]:=heap[c]; pos[heap[p]]:=p; p:=c;
    until false;
    heap[p]:=i; pos[i]:=p;
  end;

procedure update(ps:longint);
  var
    i,p,c:longint;

  begin
    i:=heap[ps]; c:=ps;
    repeat
      p:=c div 2;
      if (p=0) or (dis[i]>=dis[heap[p]]) then break;
      heap[c]:=heap[p]; pos[heap[c]]:=c; c:=p;
    until false;
    heap[c]:=i; pos[i]:=c;
  end;

procedure push(v:longint);
  begin
    inc(nheap);
	heap[nheap]:=v; pos[v]:=nheap;
	update(nheap);
  end;

begin
  
  fillchar(deg,sizeof(deg),0);
  fillchar(intree,sizeof(intree),false);
  
  readln(n,m,x);
  for i:=1 to m do
    begin
	  readln(a[i],b[i],c[i]);
	  inc(deg[a[i]]); inc(deg[b[i]]);
	end;
  for i:=1 to n+1 do deg[i]:=deg[i]+deg[i-1];
  for i:=1 to m do
    begin
	  z[deg[a[i]]]:=b[i]; h[deg[a[i]]]:=i;
	  z[deg[b[i]]]:=a[i]; h[deg[b[i]]]:=i;
	  dec(deg[a[i]]); dec(deg[b[i]]);
	end;
  
  intree[1]:=true; ans:=0; nheap:=n-1;
  
  for i:=2 to n do
    begin
	  dis[i]:=infinite;
	  road[i]:=-1;
	  heap[i-1]:=i; pos[i]:=i-1;
	end;
  
  for i:=1 to deg[2] do
    begin
	  dis[z[i]]:=c[h[i]];
	  road[z[i]]:=h[i];
	  update(pos[z[i]]);
	end;
  
  //for i:=2 to n do push(i);
  
  for i:=2 to n do
    begin
	  v:=pop; intree[v]:=true;
	  ans:=ans+x-c[road[v]]; used[road[v]]:=true;// writeln(v,' ',road[v]);
	  for j:=deg[v]+1 to deg[v+1] do
	    begin
		  //writeln('check #',z[j]);
		  u:=z[j]; if intree[u] then continue;
		  //writeln('ok    #',u);
		  if dis[u]>c[h[j]] then
		    begin
			  dis[u]:=c[h[j]];
			  road[u]:=h[j];
			  update(pos[u]);
			end;
		end;
	  //for j:=1 to n do write(dis[j]:5); writeln;
	  //for j:=1 to n do write(road[j]:5);writeln;
	  //writeln;
	end;
  
  for i:=1 to m do
    begin
	  if used[i] then continue;
	  if c[i]<x then ans:=ans+x-c[i];
	end;
  
  writeln(ans);
  
end.
