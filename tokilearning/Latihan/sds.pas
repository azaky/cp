var
  n,i:longint;
  max,min,avg,a,sq,sd:extended;

begin
  avg:=0; sq:=0; min:=1e50; max:=-1e50;
  readln(n);
  for i:=1 to n do
    begin
      readln(a);
      avg:=avg+a/n;
      sq:=sq+a*a;
      if a>max then max:=a;
      if a<min then min:=a;
    end;
  sd:=sqrt((sq-n*avg*avg)/(n-1));
  writeln(min:0:2,' ',max:0:2,' ',avg:0:2,' ',sd:0:2);
end.
