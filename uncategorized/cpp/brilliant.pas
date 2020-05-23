var
  p, n : longint;

begin
  p := 1;
  for n := 1 to 1000 do
    begin
      p := (p*13) mod 2013;
      if (p = 1) then begin writeln(n); break; end;
    end;
end.
