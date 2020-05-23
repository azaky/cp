var
  n,m,i,k,a,b,imin,imax:longint;
  gaji:array[1..50000] of longint;
  max,min:array[1..50000,0..16] of longint;
  p:array[0..16] of longint;

begin
  readln(n,m);
  for i:=1 to n do readln(gaji[i]);
  for i:=1 to n do
    begin
      max[i,0]:=i;
      min[i,0]:=i;
    end;
  p[0]:=1;
  for k:=1 to trunc(ln(n)/ln(2)) do
    begin
      p[k]:=2*p[k-1];
      for i:=1 to n-p[k]+1 do
        begin
          if gaji[max[i,k-1]]>=gaji[max[i+p[k-1],k-1]] then max[i,k]:=max[i,k-1]
            else max[i,k]:=max[i+p[k-1],k-1];
          if gaji[min[i,k-1]]<=gaji[min[i+p[k-1],k-1]] then min[i,k]:=min[i,k-1]
            else min[i,k]:=min[i+p[k-1],k-1];
        end;
    end;
  for i:=1 to m do
    begin
      readln(a,b);
      k:=trunc(ln(b-a+1)/ln(2));
      if gaji[max[a,k]]>=gaji[max[b-p[k]+1,k]] then imax:=max[a,k]
        else imax:=max[b-p[k]+1,k];
      if gaji[min[a,k]]<=gaji[min[b-p[k]+1,k]] then imin:=min[a,k]
        else imin:=min[b-p[k]+1,k];
      writeln(gaji[imax]-gaji[imin]);
    end;
end.
