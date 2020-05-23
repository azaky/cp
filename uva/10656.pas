var
  N,last,i:longint;
  a:array[0..111111] of longint;

begin
  repeat
    readln(N); if n = 0 then break;
    last := 0;
    for i:=1 to n do readln(a[i]);
    for i:=1 to n do
      if a[i]>0 then last := i;
    if last = 0 then writeln(0)
      else for i:=1 to n do
        if a[i]>0 then
          if i=last then writeln(a[i]) else write(a[i],' ');
  until false;
end.
