var
  n,max,i,x,imax:longint;

begin
  readln(n);
  max:=0;
  for i:=1 to n do
    begin
      readln(x);
      if x>max then
        begin
          imax:=i;
          max:=x;
        end;
    end;
  writeln(imax,' ',max);
end.
