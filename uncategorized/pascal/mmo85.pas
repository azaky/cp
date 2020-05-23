var
  i,n:integer;
  x,y,tempx,tempy:int64;

begin
  readln(n);
  x:=1; y:=1;
  for i:=3 to n-1 do
    begin
      tempx:=x; tempy:=y;
      if ((x+y) div 2) mod 2=1 then
        begin
          x:=(tempx+tempy) div 2;
          y:=abs(7*tempx-tempy) div 2;
        end
      else
        begin
          x:=abs(tempx-tempy) div 2;
          y:=(7*tempx+tempy) div 2;
        end;
    end;
  writeln(x,' ',y);
end.

var
  n,x,y,i:longint;
  goal,rest:int64;

begin
  readln(n);
  goal:=1; for i:=1 to n do goal:=goal*2;
  x:=-1;
  while true do
    begin
      inc(x,2);
      rest:=goal-7*int64(x)*int64(x);
      y:=trunc(sqrt(rest));
      if sqr(y)=rest then break;
    end;
  writeln(x,' ',y);
end.
