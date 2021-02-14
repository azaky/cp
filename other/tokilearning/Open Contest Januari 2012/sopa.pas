var
  n,m,i,ncom,d,furthest,ans:longint;
  a,b,adj,deg,v,com:array[0..50000] of longint;

procedure fill(v,depth:longint);
  var
    i:longint;
    
  begin
    if not(com[v]=0) then exit;
    com[v]:=ncom; if depth>d then begin d:=depth; furthest:=v; end;
    for i:=deg[v]+1 to deg[v+1] do fill(adj[i],depth+1);
  end;

procedure fill2(v,depth:longint);
  var
    i:longint;
  
  begin
    if com[v]=0 then exit;
    com[v]:=0; if depth>d then begin d:=depth; end;
    for i:=deg[v]+1 to deg[v+1] do fill2(adj[i],depth+1);
  end;

procedure sort(l,r:longint);
  var
    i,j,mid,temp:longint;
  
  begin
    i:=l; j:=r; mid:=v[random(r-l+1)+l];
    repeat
      while v[i]>mid do inc(i);
      while v[j]<mid do dec(j);
      if i>j then break else temp:=v[i]; v[i]:=v[j]; v[j]:=temp;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  readln(n,m);
  for i:=1 to m do
    begin
      readln(a[i],b[i]);
      inc(deg[a[i]]); inc(deg[b[i]]);
    end;
  for i:=1 to n+1 do deg[i]:=deg[i]+deg[i-1];
  for i:=1 to m do
    begin
      adj[deg[a[i]]]:=b[i]; adj[deg[b[i]]]:=a[i];
      dec(deg[a[i]]); dec(deg[b[i]]);
    end;
  //floodfill;
  ncom:=0;
  for i:=1 to n do
    begin
      if com[i]>0 then continue else inc(ncom);
      d:=0;
      fill(i,1);
      d:=0;
      fill2(furthest,1);
      v[ncom]:=(d div 2) + 1;
      fill(i,1);
    end;
  randomize; sort(1,ncom); ans:=0;
  for i:=1 to ncom do
    if (i-1)+v[i]>ans then ans:=(i-1)+v[i];
  writeln(ans);
end.
