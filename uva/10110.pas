var
  n:int64;

begin
  repeat
    readln(n); if n=0 then break;
	if ((sqrt(n)-trunc(sqrt(n)))<1e-9) then writeln('yes')
	  else writeln('no');
  until false;
end.
//00:05:48.509