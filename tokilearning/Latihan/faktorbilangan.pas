var
  n,i:longint;

begin
  readln(n);
  for i:=n downto 1 do
    if n mod i=0 then writeln(i);
end.
