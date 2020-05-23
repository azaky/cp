const
  maxcase=20;
  maxsize=500;
  maxn=500;
  maxmove=500;

var
  t,kasus,x0,y0,x,y,n,dir,i,j,task,k:integer;
  f:text;

begin
  assign(f,'tes.in');
  rewrite(f);
  randomize;
  kasus:=random(maxcase)+1;
  for t:=1 to kasus do
    begin
      x0:=random(maxsize);
      y0:=random(maxsize);
      n:=random(maxn)+1;
      writeln(f,x0,' ',y0,' ',n);
      for i:=1 to n do
        begin
          x:=random(x0);
          y:=random(y0);
          dir:=random(4);
          write(f,x,' ',y,' ');
          case dir of
              0:writeln(f,'T');
              1:writeln(f,'B');
              2:writeln(f,'U');
              3:writeln(f,'S');
            end;
          k:=random(maxmove)+1;
          for j:=1 to k do
            begin
              task:=random(3);
              case task of
                  0:write(f,'F');
                  1:write(f,'L');
                  2:write(f,'R');
                end;
            end;
          writeln(f);
        end;
    end;
  writeln(f,'0 0 0');
  close(f);
end.
