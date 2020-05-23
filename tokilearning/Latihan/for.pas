var
  n,sum,a,i:longint;

begin
  read(n);
  sum:=0;
  for i:=1 to n do
    begin
      read(a);
      sum:=sum+a;
    end;
  writeln(sum);
end.
