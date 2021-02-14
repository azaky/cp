var
  a,b,c,d,i,j,k:longint;
  x,y,z:array[1..75,1..75] of longint;

begin
  readln(a,b);
  for i:=1 to a do
    for j:=1 to b do read(x[i,j]);
  readln(c,d);
  for i:=1 to c do
    for j:=1 to d do read(y[i,j]);
  for i:=1 to a do
    for j:=1 to d do
      for k:=1 to b do z[i,j]:=z[i,j]+x[i,k]*y[k,j];
  for i:=1 to a do
    for j:=1 to d do
      if j=d then writeln(z[i,j])
        else write(z[i,j],' ');
end.