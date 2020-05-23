var
  i,j:longint;

begin
  writeln(9999);
  for i:=1 to 500 do
    begin
      for j:=1 to 19 do writeln(j);
    end;
  for j:=1 to 499 do writeln(j+500);
  writeln(20);
end.
