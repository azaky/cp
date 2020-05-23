var
  n,i:longint;
  a:array[0..40] of int64;

begin
  readln(n);
  n:=n div 1000;
  a[0]:=1;
  a[1]:=2;
  for i:=2 to n do a[i]:=2*a[i-1]+3*a[i-2];
  writeln(a[n])
end.