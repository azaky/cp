var
  n,i:longint;

begin
  readln(n);
  for i:=1 to n do
    if i>93 then break
      else if i=93 then writeln('ERROR')
        else if i mod 10<>0 then writeln(i);
end.
