var
  n,i:longint;
  a:array[0..1000] of int64;

begin
  readln(n,a[1],a[0]);
  for i:=2 to n do a[i]:=a[i-2]-a[i-1];
  writeln(a[n]);
end.