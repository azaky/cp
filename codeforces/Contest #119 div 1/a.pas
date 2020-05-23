var
  n,i,ia,ib:longint;
  a,b:array[0..211111] of longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  ia := 1; ib := 1;
  while true do
    begin
      //finding a[ia]
      while (b[ib]<>a[ia]) and (ib<=n) do inc(ib);
      if ib>n then break else inc(ia);
      if ia>n then break;
    end;
  writeln(n-ia+1);
end.
