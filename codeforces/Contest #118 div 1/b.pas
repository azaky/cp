var
  s,c,i:longint;
  a:array[0..4] of longint;

begin
  readln(s);
  c:=3;
  readln(a[1],a[2],a[3]);
  for i:=1 to 3 do
    if a[i]=0 then dec(c);
  if c=0 then
    begin
      writeln(0,' ',0,' ',0);
    end
  else
    begin
      for i:=1 to 3 do
        begin
          if a[i]=0 then write(0) else write(s/c:0:10);
          if i=3 then writeln else write(' ');
        end;
    end;
end.
