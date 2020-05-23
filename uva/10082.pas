var
  s:ansistring;
  i:longint;
  next:array[chr(0)..chr(255)] of char;

begin
  s:='`1234567890-=';
  for i:=length(s) downto 2 do next[s[i]]:=s[i-1];
  s:='QWERTYUIOP[]\';
  for i:=length(s) downto 2 do next[s[i]]:=s[i-1];
  s:='ASDFGHJKL;''';
  for i:=length(s) downto 2 do next[s[i]]:=s[i-1];
  s:='ZXCVBNM,./';
  for i:=length(s) downto 2 do next[s[i]]:=s[i-1];
  next[' ']:=' ';
  repeat
    readln(s);
	for i:=1 to length(s) do write(next[s[i]]); writeln;
  until eof;
end.
