var
  n,m,i,a,b,j,k,p,t,u,c:longint;
  an,cycle:boolean;
  deg,root,flag,prev:array[0..101] of longint;
  adj:array[1..100,1..100] of longint;
  visit:array[1..100] of boolean;

procedure fill(v,l:longint);
  var
    i:longint;
  
  begin
    //writeln(v,' ',prev[v]);
    if visit[v] or cycle then exit else visit[v]:=true;
	for i:=1 to deg[v] do
	  begin
	    u:=adj[v,i];
		if u=k then
		  begin
	        if l>=2 then
			  begin
			    cycle:=true;
				prev[k]:=v;
			  end;
			continue;
	      end
		else if visit[u] then continue;
		prev[u]:=v; fill(u,l+1);
	  end;
  end;

function check(v,p,f:longint):boolean;
  var
    i:longint;

  begin
    if flag[v]>0 then exit(false) else flag[v]:=f;
	for i:=1 to deg[v] do
	  if adj[v,i]=p then continue
	    else if not check(adj[v,i],v,f) then exit(false);
	exit(true);
  end;

procedure flood(v:longint);
  var
    i:longint;
  
  begin
    if visit[v] then exit else visit[v]:=true; inc(c);
	for i:=1 to deg[v] do flood(adj[v,i]);
  end;

begin
  readln(n,m); if m<>n then begin writeln('NO'); halt; end else an:=false;
  for i:=1 to m do
    begin
	  readln(a,b);
	  inc(deg[a]); inc(deg[b]);
	  adj[a,deg[a]]:=b; adj[b,deg[b]]:=a;
	end;
  //writeln;
  //finding the cycles
  c:=0; flood(1); if c=n then
  for k:=1 to 1 do
    begin
	  fillchar(prev,sizeof(prev),0);
	  fillchar(visit,sizeof(visit),false);
	  cycle:=false; fill(k,0);
	  if not cycle then continue else an:=true;
	  //writeln(k);
	  //for i:=1 to n do writeln(i,'->',prev[i]);
	  p:=0; t:=k;
	  repeat
	    inc(p); root[p]:=t; t:=prev[t];
	  until t=k;
	  root[p+1]:=root[1]; root[0]:=root[p];
	  //for i:=1 to p do write(root[i],' '); writeln;
	  fillchar(flag,sizeof(flag),255);
	  for i:=1 to p do flag[root[p]]:=i;
	  for i:=1 to p do
	    begin
		  for j:=1 to deg[root[i]] do
		    begin
			  u:=adj[root[i],j]; if (u=root[i-1]) or (u=root[i+1]) then continue;
			  if not check(u,root[i],i) then
			    begin
				  an:=false;
				  break;
				end;
			end;
		  if not an then break;
		end;
	  if not an then break;
	end;
  if an then writeln('FHTAGN!') else writeln('NO');
end.
