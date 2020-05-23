var
  n,m,a,b,i:longint;
  bi:boolean;
  deg,col,visit:array[0..200] of longint;
  adj:array[0..200,0..200] of longint;

procedure color(v,c:longint);
  var
    i:longint;
  
  begin
    //writeln(v,' ',c);
    if not bi then exit else inc(visit[v]);
    if col[v]<0 then col[v]:=c;
    if col[v]<>c then
	  begin
	    bi:=false; exit;
	  end;
	if visit[v]=1 then
	  for i:=1 to deg[v] do color(adj[v,i],(c+1) mod 2);
  end;

begin
  repeat
    readln(n); if n=0 then break; bi:=true;
	readln(m); fillchar(deg,sizeof(deg),0);
	for i:=1 to m do
	  begin
	    readln(a,b);
		inc(deg[a]); inc(deg[b]);
		adj[a,deg[a]]:=b; adj[b,deg[b]]:=a;
	  end;
	fillchar(col,sizeof(col),255);
	fillchar(visit,sizeof(visit),0);
	color(0,1);
	if not bi then write('NOT '); writeln('BICOLORABLE.')
  until false;
end.
//00:20:07.853