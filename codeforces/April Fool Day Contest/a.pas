var
  a,b:int64;
  i:longint;
  temp,s:ansistring;

begin
  readln(a,b); s:='';
  str(b,temp); for i:=length(temp) downto 1 do s:=s+temp[i]; val(s,b);
  writeln(a+b);
end.
