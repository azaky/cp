const
  tab:array[2..9] of string = ('ABC','DEF','GHI','JKL','MNO','PQRS','TUV','WXYZ');

var
  i,j:longint;
  num:array[chr(0)..chr(255)] of char;
  s:ansistring;
  ch:char;

begin
  for i:=2 to 9 do
    for j:=1 to length(tab[i]) do num[tab[i][j]]:=chr(i+ord('0'));
  num['-']:='-';
  for ch:='0' to '9' do num[ch]:=ch;
  repeat
    readln(s);
	for i:=1 to length(s) do write(num[s[i]]); writeln;
  until eof;
end.
