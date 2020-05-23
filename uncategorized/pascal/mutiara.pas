var
  n,a,b,c,m:int64;
  
begin
  readln(n);
  a:=n div 11;
  while a>=0 do
    begin
      m:=n-a*11;
      c:=m div 7;
      while (m-7*c) mod 3<>0 do dec(c);
      if c>=0 then
        begin
          writeln(19*a+2*c+5*((m-7*c) div 3));
          break;
        end
      else dec(a);
    end;
  if a<0 then writeln(-1);
end.