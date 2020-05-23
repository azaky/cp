const
  maxn = 300;

var
  a,b:int64;
  tc,n,nc,i,ta,tb,count:longint;
  deg:array[1..300] of longint;
  p:array[1..300] of int64;
  visit:array[1..300] of boolean;
  adj:array[1..300,1..300] of longint;

function search(a:int64):longint;
  var
    i:longint;
  
  begin
    if n<>0 then
	  for i:=1 to n do
	    if p[i]=a then exit(i);
	inc(n); p[n]:=a; exit(n);
  end;

procedure find(v,ttl:longint);
  var
    i:longint;
  
  begin
    if (ttl<0) or visit[v] then exit
	  else visit[v]:=true;
	inc(count);
	for i:=1 to deg[v] do find(adj[v,i],ttl-1);
  end;

begin
  tc:=0;
  while true do
    begin
	  read(nc); if nc=0 then break;
	  n:=0; fillchar(deg,sizeof(deg),0);
	  for i:=1 to nc do
	    begin
		  read(a,b);
		  ta:=search(a); tb:=search(b);
		  inc(deg[ta]); inc(deg[tb]);
		  adj[ta,deg[ta]]:=tb; adj[tb,deg[tb]]:=ta;
		end;
	  while true do
	    begin
		  read(a,ta); if (a=0) and (ta=0) then break;
		  fillchar(visit,sizeof(visit),false); count:=0; find(search(a),ta); inc(tc);
		  writeln('Case ',tc,': ',n-count,' nodes not reachable from node ',a,' with TTL = ',ta,'.');
		end;
	end;
end.
