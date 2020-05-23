var
  tc,kasus,n,i,j,best,sum:longint;
  a:array[1..100] of longint;
  pos:array[0..50000] of boolean;

begin
  read(tc);
  for kasus:=1 to tc do
    begin
	  read(n); for i:=1 to n do read(a[i]);
	  fillchar(pos,sizeof(pos),false); pos[0]:=true;
	  sum:=0; for i:=1 to n do sum:=sum+a[i]; best:=0;
	  for i:=1 to n do
	    for j:=sum div 2 downto a[i] do
		  if pos[j-a[i]] then
		    begin
			  pos[j]:=true;
		      if j>best then best:=j;
	        end;
	  writeln(sum-2*best);
	end;
end.
