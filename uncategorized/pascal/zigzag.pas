var
  n,i,count:longint;
  zigzag:boolean;
  a:array[1..1000000] of longint;

begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  zigzag:=true;
  count:=0;
  for i:=2 to (n-1) do
    if ((a[i-1]>a[i]) and (a[i]>a[i+1])) or ((a[i+1]>a[i]) and (a[i]>a[i-1])) then
      begin
        zigzag:=false;
        if count<3 then
          begin
            inc(count);
            if count=3 then writeln(i) else write(i,' ');
          end;
      end;
  if zigzag then writeln('ZIGZAG');
end.