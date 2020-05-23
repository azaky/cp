var
  i,n,nn:longint;
  a,ind:array[1..100000] of longint;

procedure sort(l,r:longint);
  var
    i,j,p,mida,midi,temp:longint;
  
  begin
    i:=l; j:=r; p:=random(r-l+1)+l; mida:=a[p]; midi:=ind[p];
	repeat
	  while (a[i]<mida) or ((a[i]=mida) and (ind[i]<midi)) do inc(i);
	  while (a[j]>mida) or ((a[j]=mida) and (ind[j]>midi)) do dec(j);
	  if i>j then break else temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
	  temp:=ind[i]; ind[i]:=ind[j]; ind[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

procedure sorti(l,r:longint);
  var
    i,j,p,mid,temp:longint;
  
  begin
    i:=l; j:=r; p:=random(r-l+1)+l; mid:=ind[p];
	repeat
	  while ind[i]<mid do inc(i);
	  while ind[j]>mid do dec(j);
	  if i>j then break else temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
	  temp:=ind[i]; ind[i]:=ind[j]; ind[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sorti(l,j);
	if i<r then sorti(i,r);
  end;

begin
  readln(n); randomize;
  for i:=1 to n do readln(a[i]);
  for i:=1 to n do ind[i]:=i;
  sort(1,n); nn:=1;
  for i:=2 to n do
    if a[i]<>a[i-1] then
	  begin
	    inc(nn);
		a[nn]:=a[i]; ind[nn]:=ind[i];
	  end;
  sorti(1,nn);
  for i:=1 to nn do writeln(a[i]);
end.
