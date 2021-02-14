var
  n, i, j, temp, ans : longint;
  a : array[0..1111] of longint;

begin
  readln(n);
  for i := 1 to n do readln(a[i]);
  for i := 1 to n-1 do
    for j := n downto i+1 do
      if (a[j] < a[j-1]) then
        begin
          inc(ans);
          temp := a[j]; a[j] := a[j-1]; a[j-1] := temp;
        end;
  writeln(ans);
end.
