var
  n,i,temp:longint;
  a,u,ans:array[1..100005] of longint;

procedure sort(l,r:longint);
  var
    i,j,midu,mida,tu,ta:longint;
  
  begin
    i:=l; j:=r; mida:=a[(l+r) div 2]; midu:=u[(l+r) div 2];
	repeat
	  while (a[i]<mida) or ((a[i]=mida) and (u[i]<midu)) do inc(i);
	  while (a[j]>mida) or ((a[j]=mida) and (u[j]>midu)) do dec(j);
	  if i>j then break;
	  ta:=a[i]; a[i]:=a[j]; a[j]:=ta;
	  tu:=u[i]; u[i]:=u[j]; u[j]:=tu;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

function max(a,b:longint):longint;
  begin
    if a>b then exit(a)
	  else exit(b);
  end;
  
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do u[i]:=i;
  sort(1,n);
  temp:=0;
  for i:=1 to n do
    begin
	  if u[i]<temp then ans[u[i]]:=temp-u[i]-1
	    else ans[u[i]]:=-1;
	  temp:=max(temp,u[i]);
	end;
  for i:=1 to n-1 do write(ans[i],' ');
  writeln(ans[n]);
end.
