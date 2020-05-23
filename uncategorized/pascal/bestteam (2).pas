var
  t,kasus,n,i,j,k,max:longint;
  p:array[1..50,1..50] of integer;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      for i:=1 to n do
        for j:=1 to n do read(p[i,j]);
      max:=0;
      for i:=1 to n-2 do
        for j:=i+1 to n-1 do
          for k:=j+1 to n do
            if p[i,j]*p[j,k]*p[k,i]>max then max:=p[i,j]*p[j,k]*p[k,i];
      writeln(max);
    end;
end.
