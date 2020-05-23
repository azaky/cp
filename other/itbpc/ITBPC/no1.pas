program no1;

var
  cube:array[1..200,1..200,1..200] of longint;
  temp:array[1..10000] of longint;
  n,i,tipe,x,y,z,x1,x2,y1,y2,z1,z2,sum,a,b,c,q:longint;

begin
  readln(n);
  for i:=1 to n do
    begin
      read(tipe);
      if tipe=0 then
        begin
          readln(x,y,z,q);
          cube[x,y,z]:=cube[x,y,z]+q;
        end;
      if tipe=1 then
        begin
          readln(x1,y1,z1,x2,y2,z2);
          sum:=0;
          for a:=x1 to x2 do
            for b:=y1 to y2 do
              for c:=z1 to z2 do
                sum:=sum+cube[a,b,c];
          writeln(sum);
        end;
    end;
end.