var
  t,kasus,n,max,imax,hasil,i,a:integer;
  
begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      max:=0;
      hasil:=1;
      for i:=1 to n do hasil:=hasil*2;
      for i:=1 to hasil do
        begin
          read(a);
          if a>max then
            begin
              max:=a;
              imax:=i;
            end;
        end;
      writeln(imax);
    end;
end.