var
  n,i,j,count:longint;
  buka:array[1..1000000] of boolean;

begin
  readln(n);
  for i:=1 to n do buka[i]:=false;
  for i:=1 to n do
    for j:=1 to (n div i) do buka[j*i]:=not(buka[j*i]);
  count:=0;
  for i:=1 to n do if buka[i] then inc(count);
  writeln(count);
  writeln(trunc(sqrt(n)));
end.

{var
  n:longint;

begin
  readln(n);
  writeln(trunc(sqrt(n)));
end.}
