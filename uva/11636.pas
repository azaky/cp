var
  n,tc:longint;

begin
  repeat
    readln(n);
	if n<0 then break else inc(tc);
	write('Case ',tc,': ');
	if n=1 then writeln(0)
	  else writeln(trunc(ln(n-1)/ln(2))+1);
  until false;
end.
