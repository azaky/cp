const
  maxn=100;
  maxe=100;

var
  n,e,i,x:integer;
  f:text;

begin
  assign(f,'tes.in');
  rewrite(f);
  n:=random(maxn);
  e:=random(maxe);
  //n:=maxn;
  //e:=maxe;
  for i:=1 to n do
    begin
      x:=random(10);
      write(f,x);
    end;
  writeln(f);
  writeln(f,e);
  close(f);
  writeln(n,' ',e);
end.
