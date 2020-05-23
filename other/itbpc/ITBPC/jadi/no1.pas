var
  x,y,z,q:array[1..10000] of longint;
  n,num1,i,j,x1,x2,y1,y2,z1,z2,result:longint;
  tipe:byte;

begin
  readln(n);
  num1:=0;
  for i:=1 to n do
    begin
      read(tipe);
      if tipe = 0 then
        begin
          inc(num1);
          readln(x[num1],y[num1],z[num1],q[num1]);
        end;
      if tipe = 1 then
        begin
          readln(x1,y1,z1,x2,y2,z2);
          result:=0;
          for j:=1 to num1 do
            if (x[j]>=x1) and (x[j]<=x2) and (y[j]>=y1) and (y[j]<=y2) and (z[j]>=z1) and (z[j]<=z2)
              then result:=result + q[j];
          writeln(result);
        end;
    end;
end.

