var
  min,max,n:integer;
  
begin
  min:=0;
  max:=0;
  while not eof do
    begin
      readln(n);
      if (n=0) then
        begin
          writeln(min,' ',max);
          min:=0;
          max:=0;
        end
      else
        begin
          if (min=0) or (min>n) then min:=n;
          if (max=0) or (max<n) then max:=n;
        end;
    end;
  writeln(min,' ',max);
end.
 