var
  n,m,i,best,a,b:longint;
  deg:array[0..24] of longint;
  adj,edge:array[0..24,1..3] of longint;
  used:array[0..24] of boolean;

procedure walk(v,k:longint);
  var
    i:longint;
  
  begin
    if k>best then best:=k;
	for i:=1 to deg[v] do
	  if not used[edge[v,i]] then
	    begin
		  used[edge[v,i]]:=true; walk(adj[v,i],k+1); used[edge[v,i]]:=false;
		end;
  end;

begin
  repeat
    readln(n,m); if n+m=0 then break else fillchar(deg,sizeof(deg),0); best:=0;
	for i:=1 to m do
	  begin
	    readln(a,b);
		inc(deg[a]); inc(deg[b]); adj[a,deg[a]]:=b; adj[b,deg[b]]:=a;
		edge[a,deg[a]]:=i; edge[b,deg[b]]:=i;
	  end;
	for i:=0 to n-1 do
	  begin
	    fillchar(used,sizeof(used),false);
		walk(i,0);
	  end;
	writeln(best);
  until false;
end.
