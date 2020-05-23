var
  i:longint;
  s:ansistring;

begin
  readln(s);
  for i:=1 to length(s) do
    if s[i]=' ' then write(' ') else write(chr((((ord(upcase(s[i]))-ord('A')+10) mod 26)+1)+ord('A')-1));
end.
