var
  n,i,j,max:longint;
  s:ansistring;
  ch,next:char;
  count:array['A'..'Z'] of longint;

begin
  readln(n);
  for i:=1 to n do
    begin
	  readln(s);
	  for j:=1 to length(s) do
	    if s[j] in ['a'..'z','A'..'Z'] then inc(count[upcase(s[j])]);
	end;
  for i:=1 to 26 do
    begin
	  max:=0;
	  for ch:='A' to 'Z' do
	    if count[ch]>max then
		  begin
		    next:=ch; max:=count[ch];
		  end;
	  if max=0 then break;
	  writeln(next,' ',count[next]); count[next]:=-1;
	end;
end.
//00:06:02.457