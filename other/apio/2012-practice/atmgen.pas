var
  n,m,i,s,p:longint;

begin
  n:=400000; m:=n-1; randomize;
  writeln(n,' ',m);
  for i:=1 to m do writeln(i,' ',i+1);
  for i:=1 to n do writeln(random(4000));
  s:=random(n)+1; p:=random(n)+1;
  writeln(s,' ',p);
  for i:=1 to p do write(random(n)+1,' ');writeln;
end.
