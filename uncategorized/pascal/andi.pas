var
  n,k,possibility,i:longint;

begin
  readln(n,k);
  possibility:=0;
  for i:=0 to ((k+n) div 5) do
    if (4*i-k>=0) then
      begin
        writeln(i,' ',(4*i-k),' ',(n+k-5*i));
        inc(possibility);
      end;
  if possibility=0 then writeln('-');
end.
