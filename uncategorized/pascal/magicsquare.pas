var
  t,i:longint;
  n:int64;

begin
  readln(t);
  for i:=1 to t do
    begin
      readln(n);
      writeln((n*(sqr(n)+1)) div 2);
    end;
end.

