var
  n:int64;

begin
  repeat
    readln(n); if n<0 then break
	else writeln(((n*(n+1)) div 2)+1);
  until false;
end.
