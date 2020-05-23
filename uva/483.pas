var
  s,temp:ansistring;
  i,n:longint;

begin
  while not eof do
    begin
	  readln(s); temp:=''; n:=length(s);
	  for i:=1 to n do
	    if s[i]=' ' then
		  begin
		    write(temp); write(' '); temp:='';
		  end
		else temp:=s[i]+temp;
	  writeln(temp);
	end;
end.