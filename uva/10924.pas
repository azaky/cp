var
  s:string;
  n,i:longint;

begin
  repeat
    readln(s); n:=0;
	for i:=1 to length(s) do
	  if s[i] in ['a'..'z'] then n:=n+ord(s[i])-ord('a')+1
	    else n:=n+ord(s[i])-ord('A')+27;
	if n=1 then writeln('It is a prime word.')
	else for i:=2 to n do
	  if i>trunc(sqrt(n)) then
	    begin
		  writeln('It is a prime word.');
		  break;
		end
	  else if n mod i=0 then
	    begin
		  writeln('It is not a prime word.');
		  break;
		end;
  until eof;
end.
