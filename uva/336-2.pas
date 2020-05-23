const
  maxn = 30;
  inf = 1000000001;

var
  tc,nc,n,i,j,k,a,b,ta,tb,ttl,count:longint;
  cap,ans:array[1..maxn,1..maxn] of longint;
  p:array[1..maxn] of longint;

function search(a:longint):longint;
  var
    i:longint;
  
  begin
    if n<>0 then
	  for i:=1 to n do
	    if p[i]=a then exit(i);
	inc(n); p[n]:=a; exit(n);
  end;
 
begin
  while true do
    begin
	  readln(nc); if nc=0 then break else n:=0;
	  for i:=1 to maxn do
	    for j:=1 to maxn do
		  if i=j then cap[i,j]:=0
		    else cap[i,j]:=inf;
	  for i:=1 to nc do
	    begin
		  read(a,b); ta:=search(a); tb:=search(b);
		  cap[ta,tb]:=1; cap[tb,ta]:=1;
		end;
	  for k:=1 to n do
	    for i:=1 to n do
		  for j:=1 to n do
		    if cap[i,j]>cap[i,k]+cap[k,j] then cap[i,j]:=cap[i,k]+cap[k,j];
	  for i:=1 to n do
	    for ttl:=0 to n do
		  begin
		    count:=0;
			for j:=1 to n do
			  if cap[i,j]<=ttl then inc(count);
			ans[i,ttl]:=n-count;
		  end;
	  while true do
	    begin
		  read(a,ttl); if (a=0) and (ttl=0) then break else inc(tc);
		  if ttl>n then writeln('Case ',tc,': ',ans[search(a),n],' nodes not reachable from node ',a,' with TTL = ',ttl,'.')
		    else writeln('Case ',tc,': ',ans[search(a),ttl],' nodes not reachable from node ',a,' with TTL = ',ttl,'.');
		end;
	end;
end.
