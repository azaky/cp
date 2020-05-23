var
  n,m,a,b,i,j,k:longint;
  par,deg:array[1..100] of longint;
  used:array[1..100] of boolean;
  adj:array[1..100,1..100] of longint;

begin
  repeat
    readln(n,m); if n+m=0 then break;
	fillchar(used,sizeof(used),false);
	fillchar(par,sizeof(par),0);
	fillchar(deg,sizeof(deg),0);
	for i:=1 to m do
	  begin
	    readln(a,b); inc(deg[a]); adj[a,deg[a]]:=b; inc(par[b]);
	  end;
	for i:=1 to n do
	  begin
	    for j:=1 to n do if (par[j]=0) and not used[j] then break;
		for k:=1 to deg[j] do dec(par[adj[j,k]]); used[j]:=true;
		if i=n then writeln(j) else write(j,' ');
	  end;
  until false;
end.
