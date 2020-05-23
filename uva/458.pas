var
  s:ansistring;
  i:longint;

begin
  while not eof do
  begin
    readln(s);
	for i:=1 to length(s) do write(char((ord(s[i])+249) mod 256));writeln;
  end;
end.
