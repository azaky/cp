{
var
  b:longint;

function fibo(a:longint):longint;
begin
  if a<3 then
    fibo:=1
  else
    fibo:=fibo(a-1)+fibo(a-2);
end;

begin
readln(b);
writeln(fibo(b));
end.
}

var
  i,n:integer;
  f:array[0..50] of longint;

begin
  f[0]:=0;
  f[1]:=1;
  for i:=2 to 40 do f[i]:=f[i-1]+f[i-2];
  readln(n);
  writeln(f[n]);
end.
