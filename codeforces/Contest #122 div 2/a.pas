var
  n,k,ans:longint;

begin
  readln(n,k);
  ans := 0;
  while not ((3*n<=k) and (k<=5*n)) do
    begin
      inc(ans); dec(n); dec(k,2);
    end;
  writeln(ans);
end.
