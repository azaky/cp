const
  e=exp(1);

var
  tc,t:longint;
  n:extended;

begin
  readln(t);
  for tc:=1 to t do begin
  readln(n); if n=0 then writeln(1) else
  writeln(trunc((n*ln(n)-n+ln(n*(1+4*n*(1+2*n)))/6+ln(Pi)/2)/ln(10))+1)
  end;
end.
