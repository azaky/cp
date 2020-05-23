var
  s:ansistring;
  i:longint;

begin
  readln(s);
  for i:=length(s) downto 1 do write(s[i]);
  writeln;
end.
