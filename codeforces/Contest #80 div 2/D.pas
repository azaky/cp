var
  n,k,t:int64;
  i,p:longint;

begin
  readln(n,k,p);
  for i:=1 to p do
    begin
	  readln(t);
	  if k=0 then
	    begin
		  write('.');
		end
	  else if n=k then
	    begin
		  write('X');
		end
	  else if n mod 2=0 then
	    begin
		  if ((t mod 2=0) and ((t div 2)+k>n div 2)) or ((t mod 2=1) and ((t+1) div 2>n-k)) then write('X')
		    else write('.');
		end
	  else
	    begin
		  if k<=(n+1) div 2 then
		    if (t=n) or ((t mod 2=0) and ((t div 2)+(k-1)>(n-1) div 2)) then write('X') else write('.')
		  else if (t mod 2=0) or ((t mod 2=1) and (((t+1) div 2)+(k-(n div 2))>(n-(n div 2)))) then write('X')
		    else write('.');
		end;
	end;
  writeln;
end.
