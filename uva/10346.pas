var
  n,k,ans,r:int64;

begin
  while not eof do
    begin
	  readln(n,k); ans:=0; r:=0;
	  while (n>0) do
	    begin
		  ans:=ans+n;
		  r:=r+n;
		  n:=r div k;
		  r:=r-(r div k)*k;
		end;
	  writeln(ans);
	end;
end.
