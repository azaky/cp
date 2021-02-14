var
  n,i:longint;
  max,min,avg,a:extended;

begin
  avg:=0; min:=1e50; max:=-1e50;
  readln(n);
  for i:=1 to n do
    begin
      readln(a);
      avg:=avg+a/n;
      if a>max then max:=a;
      if a<min then min:=a;
    end;
  writeln(min:0:2,' ',max:0:2,' ',avg:0:2);
end.