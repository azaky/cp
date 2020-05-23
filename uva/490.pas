var
  n,max,i,j:longint;
  s:array[1..100] of string[100];
  lim,len:array[1..100] of longint;

begin
  n:=0; max:=0;
  while not eof do
    begin
	  inc(n); readln(s[n]); lim[n]:=length(s[n]); len[n]:=lim[n];
	  if lim[n]>max then max:=lim[n] else lim[n]:=max;
	end;
  for j:=1 to max do
    begin
	  for i:=n downto 1 do
	    if j<=lim[i] then
		  if j<=len[i] then write(s[i,j])
		    else write(' ');
	  writeln;
	end;
end.
