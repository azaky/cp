type      matrix = array[1..2,1..2] of int64;
const I : matrix = ((1,0),(0,1));
      F : matrix = ((0,1),(1,1));
function product(x,y:matrix):matrix;
  var
    i,j,k:longint;
    temp:matrix;
  begin
    for i:=1 to 2 do
      for j:=1 to 2 do temp[i][j]:=0;
    for i:=1 to 2 do
      for j:=1 to 2 do
        for k:=1 to 2 do
          temp[i][j]:=(temp[i][j]+x[i][k]*y[k][j]) mod 1000000;
    exit(temp);
  end;
function power(x:matrix; n:longint):matrix;
  var temp:matrix;
  begin
    if n=0 then exit(I);
    temp := power(x,n div 2);
    temp := product(temp,temp);
    if n mod 2=1 then temp:=product(temp,x);
    exit(temp);
  end;

var
  n:longint;
begin
  readln(n);
  writeln((power(F,n)[1][1]+power(F,n)[2][1]) mod 1000000);
end.
