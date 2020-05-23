const
  n=100;
  max=1000;

var
  i,p,l:longint;
  f:text;

begin
  assign(f,'tes.in');
  rewrite(f);
  randomize;
  for i:=1 to n do
    begin
      p:=random(max)+1;
      l:=random(max)+1;
      writeln(f,p,' ',l);
    end;
  close(f);
end.
