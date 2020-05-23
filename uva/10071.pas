var
  v,t:int64;

begin
  while not eof do
  begin
    readln(v,t);
	writeln(2*v*t);
  end;
end.
