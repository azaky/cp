var
  tc,kasus,n,i,max,temp,j:longint;
  pos:array[0..501] of longint;

begin
  readln(tc);
  for kasus:=1 to tc do
    begin
	  read(n); for i:=1 to n do read(pos[i]);
	  max:=maxlongint;
	  for i:=1 to n do
	    begin
		  temp:=0; for j:=1 to n do temp:=temp+abs(pos[i]-pos[j]);
		  if temp<max then max:=temp;
		end;
	  writeln(max);
	end;
end.
//00:03:09.915