var
  f1,f2:text;
  same:boolean;
  s1,s2:ansistring;

begin
  assign(f1,'prime.txt'); reset(f1);
  assign(f2,'primetest.txt'); reset(f2);
  same:=true;
  while not eof(f1) and not eof(f2) do
    begin
      readln(f1,s1); readln(f2,s2);
      if (s1<>s2) or (eof(f1) xor eof(f2)) then
        begin
          same:=false; break;
        end;
    end;
  writeln(same);
end.

