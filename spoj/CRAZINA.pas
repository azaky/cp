var
  i,n:longint;
  s:ansistring;

begin
  readln(n); readln(s);
  for i:=1 to length(s) do write(chr((ord(s[i])-((i-1) mod n))));writeln;
end.
