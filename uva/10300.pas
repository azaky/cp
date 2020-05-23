var
  n,kasus,f,i:longint;
  a,b,c,ans:int64;

begin
  readln(n);
  for kasus:=1 to n do
    begin
	  readln(f); ans:=0;
	  for i:=1 to f do
	    begin
		  readln(a,b,c);
		  ans:=ans+a*c;
		end;
	  writeln(ans);
	end;
end.
