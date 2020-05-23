var
  s:int64;

begin
  readln(s);
  if s mod 86400 = 0 then writeln(s div 86400)
    else writeln((s div 86400)+1);
end.
