var
  n:extended;

begin
  readln(n);
  if n>0 then
    begin
      write(trunc(n),' ');
      if n-trunc(n)<1e-50 then writeln(trunc(n))
        else writeln(trunc(n)+1);
    end
  else
    begin
      if trunc(n)-n<1e-50 then write(trunc(n),' ')
        else write(trunc(n)-1,' ');
      writeln(trunc(n));
    end;
end.
