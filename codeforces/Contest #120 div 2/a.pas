uses math;
var
  n,m:longint;

begin
  readln(n,m);
  if (n=0)and(m>0) then writeln('Impossible')
  else if (m=0) then writeln(n,' ',n) else
  writeln(max(n,m),' ',n+m-1);
end.
