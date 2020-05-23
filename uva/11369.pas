var
  t,kasus,n,i,ans:longint;
  p:array[1..20000] of longint;

procedure sort(l,r:longint);
  var
    i,j,mid,temp:longint;
  
  begin
    i:=l; j:=r; mid:=p[(i+j) div 2];
	repeat
	  while p[i]>mid do inc(i);
	  while p[j]<mid do dec(j);
	  if i>j then break;
	  temp:=p[i]; p[i]:=p[j]; p[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
	  readln(n); for i:=1 to n do read(p[i]);
	  sort(1,n); ans:=0;
	  for i:=1 to n div 3 do
	    ans:=ans+p[3*i];
	  writeln(ans);
	end;
end.