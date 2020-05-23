var
  t,kasus,i:integer;
  input:string;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(input);
      {
      for i:=1 to length(input) do
        if i mod 2 = 1 then write(upcase(input[i]))
          else write(input[i]);
      writeln;
      }
      for i:=0 to (length(input) div 2) do
        input[2*i+1]:=upcase(input[2*i+1]);
      writeln(input);
    end;
end.
