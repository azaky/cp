var
  a,b,c,d,x,y,z,temp,i:longint;
  solve:boolean;

begin
  while not eof do
    begin
      readln(a,b,c,d);
      x:=0;
      while (x*x-D<0) and (x<=256) do inc(x);
      dec(x);
      solve:=false;
      repeat
        inc(x);
        y:=x*x-D;
        z:=A-x*x-y*y;
        if z<0 then break;
        temp:=1;
        for i:=1 to B do
          begin
            temp:=temp*(x+y);
            if temp+y>C then break;
          end;
        if temp+y>C then break
          else if temp+y=C then
            begin
              solve:=true;
              break;
            end;
      until (x>256);
      if solve and (y>=0) and (z>=0) and (z<=65536) then writeln(x,' ',y,' ',z)
        else writeln('No solution');
    end;
end.
