var
  tc,nc,n,a,b,ta,tb,i,j,k:longint;
  path,ans:array[1..30,0..30] of longint;
  p,na,nb:array[0..10000] of longint;

function node(a:longint):longint;
  var
    l,r,mid:longint;
  
  begin
    l:=1; r:=n;
	repeat
	  mid:=(l+r) div 2;
	  if p[mid]=a then exit(mid)
	    else if p[mid]<a then l:=mid+1
		  else r:=mid;
    until false;
  end;

procedure sort(l,r:longint);
  var
    i,j,mid,temp:longint;
  
  begin
    i:=l; j:=r; mid:=p[(l+r) div 2];
	repeat
	  while p[i]<mid do inc(i);
	  while p[j]>mid do dec(j);
	  if i>j then break else temp:=p[i]; p[i]:=p[j]; p[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

begin
  tc:=0; p[0]:=0;
  repeat
    read(nc); if nc=0 then break else n:=0;
	fillchar(path,sizeof(path),255);
	for i:=1 to nc do
	  begin
	    read(na[i],nb[i]); p[2*i-1]:=na[i]; p[2*i]:=nb[i];
	  end;
	sort(1,2*nc);
	for i:=1 to 2*nc do
	  if p[i]<>p[i-1] then
	    begin
		  inc(n); p[n]:=p[i];
		end;
    for i:=1 to nc do
	  begin
	    ta:=node(na[i]); tb:=node(nb[i]);
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
	  read(a,b); if (a=0) and (b=0) then break else inc(tc); ta:=node(a);
	  if b>n then writeln('Case ',tc,': ',ans[ta,n],' nodes not reachable from node ',a,' with TTL = ',b,'.')
	    else writeln('Case ',tc,': ',ans[ta,b],' nodes not reachable from node ',a,' with TTL = ',b,'.');
	until false;
  until false;
end.
