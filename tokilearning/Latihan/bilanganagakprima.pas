var
  t,kasus,n,i,c:longint;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      if n<5 then
        begin
          writeln('YA');
          continue;
        end;
      c:=0;
      for i:=2 to trunc(sqrt(n)) do
        if n mod i=0 then
          begin
            inc(c);
            if c=2 then break;
          end;
      if c=2 then writeln('TIDAK')
        else writeln('YA');
    end;
end.
