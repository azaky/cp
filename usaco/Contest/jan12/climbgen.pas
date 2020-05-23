const
  maxn = 20;

var
  i,n:longint;

begin
  assign(output,'climb.in'); rewrite(output);
  readln(n); writeln(n);
  randomize;
  for i:=1 to n do writeln(random(maxn)+1:10,random(maxn)+1:10);
  close(output);
end.
