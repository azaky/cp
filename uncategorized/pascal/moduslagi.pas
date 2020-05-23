var
  n,max,i,x,modus:longint;
  a:array[0..1000000] of longint;

begin
  readln(n);
  max:=0;
  for i:=1 to n do
    begin
      readln(x);
      inc(a[x]);
      if a[x]>max then
        begin
          max:=a[x];
          modus:=x;
        end;
    end;
  writeln(modus);
end.
