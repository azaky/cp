var
  n,b,i,sum:longint;
  h:array[1..20000] of longint;

procedure sort(l,r:longint);
  var
    i,j,mid,temp:longint;
  
  begin
    i:=l; j:=r; mid:=h[random(r-l+1)+l];
	repeat
	  while h[i]>mid do inc(i);
	  while h[j]<mid do dec(j);
	  if i>j then break else temp:=h[i]; h[i]:=h[j]; h[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

begin
  readln(n,b); randomize;
  for i:=1 to n do readln(h[i]);
  sort(1,n); sum:=0;
  for i:=1 to n do
    begin
	  sum:=sum+h[i];
	  if sum>=b then
	    begin
		 writeln(i); halt;
		end;
	end;
  writeln('apa aja boleh..');
end.
