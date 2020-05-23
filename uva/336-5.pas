var
  tc,nc,n,a,b,ta,tb,i,j,k,t,u,qtake,qsave:longint;
  adj,ans:array[1..30,0..30] of longint;
  p,q,deg,queue:array[1..30] of longint;
  wait:array[1..30] of boolean;

function node(a:longint):longint;
  var
    i:longint;
  
  begin
    if n>0 then
	  for i:=1 to n do
	    if p[i]=a then exit(i);
    inc(n); p[n]:=a; exit(n);
  end;

begin
  tc:=0;
  repeat
    read(nc); if nc=0 then break else n:=0;
	fillchar(deg,sizeof(deg),0);
	for i:=1 to nc do
	  begin
	    read(a,b); ta:=node(a); tb:=node(b);
		inc(deg[ta]); inc(deg[tb]);
		adj[ta,deg[ta]]:=tb; adj[tb,deg[tb]]:=ta;
	  end;
	for i:=1 to n do
	  for j:=0 to n do ans[i,j]:=n;
	for i:=1 to n do
	  begin
	    queue[1]:=i; qtake:=1; qsave:=1; q[i]:=0;
		fillchar(wait,sizeof(wait),false); wait[i]:=true;
		repeat
		  t:=queue[qtake];
		  for j:=q[t] to n do dec(ans[i,j]);
		  for j:=1 to deg[t] do
		    begin
			  u:=adj[t,j];
			  if wait[u] then continue else wait[u]:=true;
			  q[u]:=q[t]+1; inc(qsave); queue[qsave]:=u;
			end;
		  inc(qtake);
		until qtake>qsave;
	  end;
	repeat
	  read(a,b); if (a=0) and (b=0) then break else inc(tc);
	  ta:=node(a);
	  if b>n then writeln('Case ',tc,': ',ans[ta,n],' nodes not reachable from node ',a,' with TTL = ',b,'.')
	    else writeln('Case ',tc,': ',ans[ta,b],' nodes not reachable from node ',a,' with TTL = ',b,'.');
	until false;
  until false;
end.
