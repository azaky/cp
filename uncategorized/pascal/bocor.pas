var
  n,m,i:longint;
  sum,k:int64;
  a,v:array[1..400000] of longint;
  t:array[1..400000] of extended;

procedure sort(l,r:longint);
  var
    i,j:longint;
	mid,temp:extended;
  
  begin
    i:=l; j:=r; mid:=t[(l+r) div 2];
	repeat
	  while t[i]>mid do inc(i);
	  while t[j]<mid do dec(j);
	  if i>j then break else temp:=t[i]; t[i]:=t[j]; t[j]:=temp;
	  inc(i); dec(j);
	until i>j;
    if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

begin
  randomize;
  readln(n,m);
  for i:=1 to n do read(v[i]); sum:=0;
  for i:=1 to n do sum:=sum+v[i];
  for i:=1 to n do a[i]:=(m*v[i]) div sum; k:=0;
  for i:=1 to n do k:=k+a[i]; k:=m-k;
  for i:=1 to n do
    if a[i]=0 then t[i]:=1e100
	  else t[i]:=v[i]/a[i];
  sort(1,n); writeln(t[k+1]:0:2);
end.
