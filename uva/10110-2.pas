var
  n,i,x:longint;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(x);
      if sqr(round(sqrt(x)))=x then writeln('no') else writeln('yes');
    end;
end.
