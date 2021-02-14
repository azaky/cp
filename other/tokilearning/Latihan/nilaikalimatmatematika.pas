var
  a,b:integer;
  op:char;

begin
  read(a); read(op); read(op); readln(b);
  case op of
    '+':writeln(a+b);
    '-':writeln(a-b);
    '*':writeln(a*b);
    '<':if a<b then writeln('benar')
          else writeln('salah');
    '>':if a>b then writeln('benar')
          else writeln('salah');
    '=':if a=b then writeln('benar')
          else writeln('salah');
  end;
end.
