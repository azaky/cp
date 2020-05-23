var
  tc,i,n,res:longint;

begin
  readln(tc);
  for i:=1 to tc do
    begin
	  readln(n); res:=315*n+36962;
	  if res>=0 then writeln((res mod 100) div 10)
	    else writeln(((-res) mod 100) div 10);
	end;
end.
