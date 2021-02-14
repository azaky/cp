var
  n,f,i,c:longint;

begin
  readln(n);
  f:=0;
  for i:=2 to trunc(sqrt(n)) do
    if n mod i=0 then
      begin
        inc(f);
        c:=0;
        while n mod i=0 do
          begin
            n:=n div i;
            inc(c);
          end;
        if f>1 then write(' x ');
        write(i);
        if c>1 then write('^',c);
      end;
  if (f=0) then writeln(n)
    else if (n>1) then writeln(' x ',n)
      else writeln;
end.
