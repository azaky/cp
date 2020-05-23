var
a, c, j:Integer;
begin
readln(a);
c:=0;
j:=1;
while j>0 do
  begin
  a:=a div 5;
  c:=c+a;
  if a=0 then j:=0 else j:=1;
  end;
write(c);
end.
