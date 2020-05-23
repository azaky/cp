var
  a,b:int64;

begin
  while not eof do
    begin
	  readln(a,b); writeln(abs(a-b));
	end;
end.