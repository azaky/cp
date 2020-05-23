var
  n,i:longint;
  a,w:array[1..100] of int64;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  w[1]:=a[1]; for i:=2 to n do w[i]:=a[i]*i-i+1+w[i-1];
  writeln(w[n]);
end.
