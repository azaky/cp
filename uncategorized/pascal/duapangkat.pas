var
  n : longint;

begin
  while true do begin
  readln(n);
  if (n = 0) then break;
  writeln((n and (-n)) = n);
  end;
end.
