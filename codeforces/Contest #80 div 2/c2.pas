var
  n,m,i,a,b,c:longint;
  deg:array[1..100] of longint;
  adj:array[1..100,1..100] of longint;
  visit:array[1..100] of boolean;

procedure flood(v:longint);
  var
    i:longint;
  
  begin
    if visit[v] then exit else visit[v]:=true; inc(c);
	for i:=1 to deg[v] do flood(adj[v,i]);
  end;

begin
  readln(n,m); if m<>n then begin writeln('NO'); halt; end;
  for i:=1 to m do
    begin
	  readln(a,b);
	  inc(deg[a]); inc(deg[b]);
	  adj[a,deg[a]]:=b; adj[b,deg[b]]:=a;
	end;
  c:=0; flood(1); if c=n then writeln('FHTAGN!') else writeln('NO');
end.