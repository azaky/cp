var
  tc,nc,n,a,b,ta,tb,i,j,k:longint;
  path,ans:array[1..30,0..30] of longint;
  p:array[1..30] of longint;

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
	fillchar(path,sizeof(path),255);
	for i:=1 to nc do
	  begin
	    read(a,b); ta:=node(a); tb:=node(b);
		path[ta,tb]:=1; path[tb,ta]:=1;
	  end;
	for i:=1 to n do path[i,i]:=0;
	for k:=1 to n do
	  for i:=1 to n do
	    for j:=1 to n do
		  begin
		    if (path[i,k]<0) or (path[k,j]<0) then continue;
			if (path[i,j]<0) or (path[i,j]>path[i,k]+path[k,j]) then
			  path[i,j]:=path[i,k]+path[k,j];
		  end;
	fillchar(ans,sizeof(ans),0);
	for i:=1 to n do
	  for j:=0 to n do
	    begin
		  for k:=1 to n do
		    if (path[i,k]<=j) and (path[i,k]>=0) then inc(ans[i,j]);
		  ans[i,j]:=n-ans[i,j];
		end;
	repeat
	  read(a,b); if (a=0) and (b=0) then break else inc(tc);
	  ta:=node(a);
	  if b>n then writeln('Case ',tc,': ',ans[ta,n],' nodes not reachable from node ',a,' with TTL = ',b,'.')
	    else writeln('Case ',tc,': ',ans[ta,b],' nodes not reachable from node ',a,' with TTL = ',b,'.');
	until false;
  until false;
end.
