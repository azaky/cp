const
  f_1='power.out';
  f_2='power2.out';

var
  f1,f2:text;
  c1,c2:char;
  same:boolean;

begin
  assign(f1,f_1);
  assign(f2,f_2);
  reset(f1);
  reset(f2);
  same:=true;
  while not(eof(f1)) and not(eof(f2)) do
    begin
      read(f1,c1);
      read(f2,c2);
      if c1<>c2 then
        begin
          same:=false;
          break;
        end;
    end;
  if ((eof(f1)) and not(eof(f2))) or ((eof(f2)) and not(eof(f1))) then same:=false;
  if same then writeln('SAME')
    else writeln('NOT SAME');
end.