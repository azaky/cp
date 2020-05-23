var

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(x[i],y[i]);
      //looking for the value of maxx, maxy, minx, miny
      if i=1 then
        begin
          maxx:=x[i];
          minx:=x[i];
          maxy:=y[i];
          miny:=y[i];
        end
      else
        begin
          if maxx<x[i] then maxx:=x[i];
          if maxy<y[i] then maxy:=y[i];
          if minx>x[i] then minx:=x[i];
          if miny>y[i] then miny:=y[i];
        end;
    end;
  //looking for the index which has value equal to maxx
  for i:=1 to n do
    if x[i]=maxx then
      if (istart=0) or (y[i]<y[istart]) then istart:=i;
  while
end.
