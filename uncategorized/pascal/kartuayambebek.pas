var
  a,b,i:integer;
  input:string;

begin
  a:=0;
  b:=0;
  for i:=1 to 6 do
    begin
      read(input);
      if input[2]='A' then inc(a) else inc(b);
    end;
  if b>=3 then writeln('100')
    else if b=2 then writeln('70')
      else if b=1 then writeln('40')
        else writeln('20');
end.