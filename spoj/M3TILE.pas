var
  f:array[-1..111] of int64;
  i,j,n:longint;

begin
  f[0] := 1;
  for i:=1 to 15 do
    begin
      f[i] := 0;
      for j:=1 to i do
        if j=1 then f[i] := f[i] + 3*f[i-j]
          else f[i]:=f[i] + 2*f[i-j];
    end;
  repeat
    readln(n);
    if n<0 then break;
    if n mod 2=1 then writeln(0) else writeln(f[n div 2]);
  until false;
end.
