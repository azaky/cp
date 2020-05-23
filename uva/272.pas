var
  s:ansistring;
  i:longint;
  left:boolean;

begin
  left:=true;
  while not eof do begin
    readln(s);
	for i:=1 to length(s) do
	  if s[i]='"' then
	    if left then
		  begin
		    left:=false;
			write('``');
		  end
		else
		  begin
		    left:=true;
			write('''''');
		  end
	  else write(s[i]);
	writeln;
  end;
end.
