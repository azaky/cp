const
  mirror:array[1..35] of char
  = ('A','.','.','.','3','.','.','H','I','L','.','J','M','.','O','.','.','.','2','T','U','V','W','X','Y','5','1','S','E','.','Z','.','.','8','.');

var
  ch:char;
  n,i:longint;
  s:ansistring;
  mir,pal:boolean;
  map:array[chr(1)..chr(255)] of longint;

begin
  for ch:='A' to 'Z' do map[ch]:=ord(ch)-ord('A')+1;
  for ch:='1' to '9' do map[ch]:=ord(ch)-ord('0')+26;
  while not eof do
    begin
	  readln(s); while s[length(s)]=' ' do delete(s,length(s),1);
	  write(s); n:=length(s); mir:=true; pal:=true;
	  for i:=1 to n div 2 do
	    begin
		  if s[i]<>s[n+1-i] then pal:=false;
		  if mirror[map[s[i]]]<>s[n+1-i] then mir:=false;
		  if not (mir or pal) then break;
		end;
	  if (n mod 2=1) and (mirror[map[s[(n+1) div 2]]]<>s[(n+1) div 2]) then mir:=false;
	  if pal and mir then writeln(' -- is a mirrored palindrome.')
	    else if pal then writeln(' -- is a regular palindrome.')
		  else if mir then writeln(' -- is a mirrored string.')
		    else writeln(' -- is not a palindrome.');
	  writeln;
	end;
end.