var
  t,i:longint;
  n,ans:int64;

begin
  readln(t);
  for i:=1 to t do
    begin
	  readln(n);
	  ans:=0;
	  while n>0 do
	    begin
		  n := n div 5;
		  inc(ans,n);
		end;
	 writeln(ans);
	end;
end.
