var
  n,k,i,j:integer;
  c:array[0..100,0..100] of int64;

begin
  readln(n,k);
  for i:=0 to k do c[i,0]:=1;
  for i:=1 to (n-k) do c[0,i]:=1;
  for i:=1 to (n-k) do
    for j:=1 to k do c[j,i]:=c[j-1,i]+c[j,i-1];
  writeln(c[k,(n-k)]);
end.
