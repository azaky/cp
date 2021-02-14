var
  n,i:longint;
  k,m:int64;
  sum,ans:extended;
  a:array[1..50000] of int64;
  t,v:array[1..50000] of extended;

procedure sortv(l,r:longint);
  var
    i,j:longint;
	mid,temp:extended;
  
  begin
    i:=l; j:=r; mid:=v[random(r-l+1)+l];
	repeat
	  while v[i]<mid do inc(i);
	  while v[j]>mid do dec(j);
	  if i>j then break else temp:=v[i]; v[i]:=v[j]; v[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sortv(l,j);
	if i<r then sortv(i,r);
  end;

begin
  randomize;
  readln(n,m);
  for i:=1 to n do read(v[i]); sum:=0; sortv(1,n);
  for i:=1 to n do sum:=sum+v[i];
  //writeln(sum);
  for i:=1 to n do a[i]:=trunc((m*v[i])/sum);
  k:=m; for i:=1 to n do dec(k,a[i]);
  for i:=1 to k do inc(a[i]);
  //for i:=1 to n do writeln(v[i]:0:2,' ',a[i],' ',v[i]/a[i]:0:10);
  ans:=0.0;
  for i:=1 to n do
    if v[i]/a[i]>ans then ans:=v[i]/a[i];
  writeln(ans:0:10);
  {
  for i:=1 to n do
    if a[i]=0 then t[i]:=1e100
	  else t[i]:=v[i]/a[i];
  sort(1,n); writeln(t[k+1]:0:2);
  }
end.
