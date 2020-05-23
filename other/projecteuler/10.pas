const
  max = 2000000;

var
  p:array[1..max] of boolean;
  i,j:longint;
  sum:int64;

begin
  for i:=2 to max do p[i]:=true;
  for i:=2 to max do
    if p[i] then
      for j:=2 to (max div i) do
        p[i*j]:=false;
  sum:=0;
  for i:=1 to max do
    if p[i] then
      begin
        inc(sum,i);
        //writeln(i);
      end;
  writeln(sum);
end.

