const
  alphabet:set of char = ['a'..'z','A'..'Z'];

var
  word,i:longint;
  s:ansistring;

begin
  while not eof do
  begin
    readln(s);word:=0;
	if s[1] in alphabet then word:=1;
	for i:=2 to length(s) do
	  if (s[i] in alphabet) and not (s[i-1] in alphabet) then inc(word);
	writeln(word);
  end;
end.
