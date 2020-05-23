var
  a,b,c,d,x,y:longint;

begin
  while not eof do
    begin
      readln(a,b,c,d);
      x:=-1;
      repeat
        inc(x);
        y:=x*x-D;
        {if (x+y<=0) or (C<=y) then
          begin
            x:=32786;
            break;
          end;
        }//writeln(x,' ',y);
      until ((y>=0) and (A>=x*x+y*y) and (abs(ln(C-y)/ln(x+y)-B)<0.01)) or (x>256);
      if x>256 then writeln('No solution')
        else writeln(x,' ',y,' ',(A-x*x-y*y));
    end;
end.
