var
  n,kasus,l,s,j,i,k:longint;
  a:array[0..51] of longint;

procedure swap(var a,b:longint);
  var
    temp:longint;
  
  begin
    temp:=a; a:=b; b:=temp;
  end;

begin
  readln(n);
  for kasus:=1 to n do
    begin
	  readln(l);
	  for i:=1 to l do read(a[i]);
	  s:=0;
	  for i:=1 to l do
	    begin
		  for j:=i to l do
		    if a[j]=i then break;
		  if i=j then continue;
		  for k:=j downto i+1 do swap(a[k],a[k-1]); s:=s+j-i;
		end;
	  writeln('Optimal train swapping takes ',s,' swaps.');
	end;
end.
//00:05:52.775