var
  n,i,a,b:longint;

begin
  readln(n);
  for i:=1 to n do
    begin
	  readln(a,b);
	  if a=b then writeln('=') else if a<b then writeln('<') else writeln('>');
	end;
end.
