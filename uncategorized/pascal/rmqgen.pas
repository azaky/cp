const
  minn = 90000; maxn = 100000;
  minnum = -2000000000; maxnum = 2000000000;
  minq = 90000; maxq = 100000;

var
  n,i,q,a,b:longint;
  x:int64;

begin
  assign(output,'text.txt'); rewrite(output);
  randomize;
  n:=random(maxn-minn+1)+minn;
  q:=random(maxq-minq+1)+minq;
  writeln(n,' ',q);
  for i:=1 to n do
    begin
      x:=random(maxnum-minnum+1)+minnum;
      if i=n then writeln(x)
        else write(x,' ');
    end;
  for i:=1 to q do
    begin
      a:=random(n)+1;
      b:=random(n)+1;
      writeln(a,' ',b);
    end;
end.
