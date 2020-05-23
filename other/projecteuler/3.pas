var
  n:int64;
  i:longint;
  
begin
  n:=600851475143;
  for i:=2 to trunc(sqrt(n)) do
    if n mod i=0 then
      begin
        writeln(i);
        while n mod i=0 do n:=n div i;
      end;
  writeln(n);
end.

