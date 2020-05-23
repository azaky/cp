const
 maxn=10000;
 maxv=1000000;

var
  i,x:longint;
  f:text;

begin
  assign(f,'tes.in');
  rewrite(f);
  randomize;
  writeln(f,maxn);
  for i:=1 to maxn do
    begin
      x:=random(maxv);
      writeln(f,x);
    end;
  close(f);
end.
