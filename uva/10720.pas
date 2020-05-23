var
  N,i,sum:longint;
  a:array[0..11111] of longint;
  valid:boolean;

begin
  repeat
    read(N); if n=0 then break;
    for i:=1 to n do read(a[i]);
    sum:=0;
    for i:=1 to n do sum := sum + a[i];
    valid := sum mod 2=0;
    for i:=1 to n do
      if a[i]>=n then valid := false;
    if valid then writeln('Possible') else writeln('Not possible');
  until false;
end.
