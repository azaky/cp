var
  n, i, j : integer;

begin
  n := 20;
  for i := 1 to n-1 do
    for j := i+1 to n do
      writeln(i,' ',j);
  writeln('0 0');
  writeln(n);
end.
