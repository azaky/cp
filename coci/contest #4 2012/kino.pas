var
  n,l,i:longint;
  s:ansistring;

begin
  readln(n); readln(s);
  for i:=1 to n do
    if s[i]='L' then inc(l);
  if l<=2 then writeln(n)
    else writeln(n-(l-2) div 2);
end.
