var
  n,i:longint;
  a:array[1..100000] of longint;

begin
  n:=0;
  while not eof do
    begin
      inc(n);
      readln(a[n]);
    end;
  for i:=n downto 1 do writeln(a[i]);
end.
