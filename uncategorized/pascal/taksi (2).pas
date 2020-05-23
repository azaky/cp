var
  t,kasus,a,b,l:longint;
  
begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(a,b,l);
      l:=l div 100;
      if l<20 then writeln(a)
        else writeln(a+b*(l-20));
    end;
end.