var
a,b:longint;

begin
readln(a);
readln(b);
while true do
  begin
  if a=0 then
    begin
    writeln(b);
    break;
    end
  else begin
  if a<=b then
    begin
    a:=a+b;
    b:=a-b;
    a:=a-b;
    end;
  a:=a mod b;
  end;
  end;
end.