var
  t,i:longint;
  n,sum4,sum7,sum28:int64;

begin
  readln(t);
  for i:=1 to t do
    begin
      readln(n);
      sum4:=4*(((n div 4)*((n div 4)+1)) div 2);
      sum7:=7*(((n div 7)*((n div 7)+1)) div 2);
      sum28:=28*(((n div 28)*((n div 28)+1)) div 2);
      writeln(sum4+sum7-sum28);
    end;
end.

