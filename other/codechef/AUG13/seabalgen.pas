var
  n, i : longint;

begin
  n := 100000;
  writeln(n,' ',n);
  for i := 1 to n do write('1 '); writeln;
  for i := 1 to n do writeln(i,' ',n);
  writeln(n);
  for i := 1 to n do writeln('1 ',i);
end.
