var
  i,n:longint;
  a,sum:int64;

begin
  readln(n); sum:=0;
  for i:=1 to n do
    begin
      read(a); inc(sum,a);
    end;
  if sum mod 24=0 then writeln(sum div 24)
    else writeln((sum div 24)+1);
end.

