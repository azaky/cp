var
  a,b,deg,path,adj:array[0..111111] of longint;
  n,i,ans:longint;

procedure dfs(par,v:longint);
  var
    child,best,best2,i:longint;
  
  begin
    child:=0;
	for i:=deg[v]+1 to deg[v+1] do
	  if adj[i]<>par then
	    begin
		  inc(child);
		  dfs(v,adj[i]);
		  if path[v]<path[adj[i]]+1 then path[v]:=path[adj[i]]+1;
		end;
	if child=0 then exit;
	if child=1 then
	  begin
		if path[v]>ans then ans:=path[v];
		exit;
	  end;
	best:=0; best2:=0;
	for i:=deg[v]+1 to deg[v+1] do
	  if (adj[i]<>par) and (path[adj[i]]>path[best]) then best:=adj[i];
	for i:=deg[v]+1 to deg[v+1] do
	  if (adj[i]<>par) and (path[adj[i]]>path[best2]) and (adj[i]<>best) then best2:=adj[i];
	if path[best]+path[best2]+2>ans then ans:=path[best]+path[best2]+2;
	//writeln(v,' ',path[v],' ',best,' ',best2);
  end;

begin
  readln(n);
  for i:=1 to n-1 do
    begin
	  readln(a[i],b[i]);
	  inc(deg[a[i]]); inc(deg[b[i]]);
	end;
  for i:=1 to n+1 do deg[i]:=deg[i]+deg[i-1];
  for i:=1 to n-1 do
    begin
	  adj[deg[a[i]]]:=b[i]; adj[deg[b[i]]]:=a[i];
	  dec(deg[a[i]]); dec(deg[b[i]]);
	end;
  path[0]:=-1;
  dfs(0,1);
  writeln(ans);
end.
