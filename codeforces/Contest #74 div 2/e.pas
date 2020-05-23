const
  next:array[1..4,1..2] of integer = ((0,-1),(-1,0),(0,1),(1,0));

var
  n,m,i,j,nc,max,nmax,d,tx,ty,cur,p:longint;
  ch:char;
  a,t:array[0..5001,0..5001] of longint;
  x,y,dir:array[1..5000] of longint;
  temp:array[1..5000,1..4,1..2] of longint;
  g,go:array[1..5000,1..4] of longint;

begin
  readln(n,m);
  for i:=1 to n do
    begin
	  for j:=1 to m do
	    begin
		  read(ch); a[i,j]:=pos(ch,'LURD');
		end;
	  readln;
	end;
  nc:=0; max:=0; nmax:=0;
  for i:=1 to n do
    for j:=1 to m do
	  begin
	    if a[i,j]=0 then continue;
	    inc(nc); x[nc]:=i; y[nc]:=j; t[i,j]:=nc; dir[nc]:=a[i,j];
		for d:=1 to 4 do
		  begin
		    tx:=i+next[d,1]; ty:=j+next[d,2];
			while (tx>0) and (ty>0) and (tx<=n) and (ty<=m) and (a[tx,ty]=0) do
			  begin
				tx:=tx+next[d,1]; ty:=ty+next[d,2];
			  end;
			if a[tx,ty]<>0 then
			  begin
				temp[nc,d][1]:=tx; temp[nc,d][2]:=ty;
			  end;
		  end;
	  end;
  for i:=1 to nc do
    for d:=1 to 4 do
	  if (temp[i,d][1]=0) or (temp[i,d][2]=0) or (temp[i,d][1]>n) or (temp[i,d][2]>m) then go[i,d]:=0
	    else go[i,d]:=t[temp[i,d][1],temp[i,d][2]];
  for i:=1 to nc do
    begin
	  g:=go;
	  p:=i; cur:=0;
	  while p<>0 do
	    begin
		  g[g[p,3],1]:=g[p,1];
		  g[g[p,1],3]:=g[p,3];
		  g[g[p,2],4]:=g[p,4];
		  g[g[p,4],2]:=g[p,2];
		  p:=g[p,dir[p]]; inc(cur);
		end;
	  if cur=max then inc(nmax)
	    else if cur>max then
		  begin
		    max:=cur; nmax:=1;
		  end;
	end;
  writeln(max,' ',nmax);
end.
