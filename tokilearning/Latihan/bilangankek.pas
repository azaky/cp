var
  n,k,i:longint;
  a:array[1..100000] of longint;

procedure sort(l,r:longint);
  var
    i,j,mid,temp:longint;
  
  begin
    i:=l; j:=r; mid:=a[random(r-l+1)+l];
	repeat
	  while a[i]>mid do inc(i);
	  while a[j]<mid do dec(j);
	  if i>j then break else temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

begin
  readln(n,k); randomize;
  for i:=1 to n do readln(a[i]);
  sort(1,n); writeln(a[k]);
end.
