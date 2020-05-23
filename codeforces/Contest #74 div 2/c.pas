var
  n,i:longint;
  m,k,max,min:int64;
  a:array[1..10000] of int64;

begin
  readln(n,m,k);
  for i:=1 to n do read(a[i]);
  if n mod 2=0 then
    begin
      writeln(0);
      halt;
    end;
  min:=1000000001;
  for i:=1 to n do
    if i mod 2=1 then
      if a[i]<min then min:=a[i];
  max:=(2*m) div (n+1);
  if max*k<min then writeln(max*k)
    else writeln(min);
end.
