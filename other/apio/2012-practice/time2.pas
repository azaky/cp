var
  s:int64;

begin
  writeln('トップページ');
  readln(s);
  if s mod 86400 <43200 then writeln(s div 86400)
    else writeln((s div 86400)+1);
end.
