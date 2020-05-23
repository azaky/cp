var
  n:longint;

function emas(n:longint):longint;
  var
    temp:longint;
  
  begin
    if n=0 then exit(0);
    temp:=emas(n div 2)+emas(n div 3)+emas(n div 4);
    if temp>n then exit(temp)
      else exit(n);
  end;

begin
  readln(n);
  writeln(emas(n));
end.

