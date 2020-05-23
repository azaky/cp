var
  n,i,j:integer;

begin
  readln(n);
  for i:=1 to n do
    begin
      for j:=1 to i do
        write((((i*(i-1)) div 2)+j-1) mod 10);
      writeln;
    end;
end.