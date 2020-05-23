var
  n,sum:longint;
  f:array[1..10000000] of longint;


begin
  f[1]:=1; f[2]:=2;
  n:=2; sum:=2;
  repeat
    inc(n);
    f[n]:=f[n-1]+f[n-2];
    if f[n]>4000000 then break
      else if f[n] mod 2=0 then inc(sum,f[n]);
  until false;
  writeln(sum);
end.

