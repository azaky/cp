var
  a,i:longint;
  f:array[0..1111] of longint;

begin
  readln(a);
  writeln(a,' 0 0'); halt;
  if a = 0 then begin writeln('0 0 0'); halt; end;
  if a = 1 then begin writeln('0 0 1'); halt; end;
  if a = 2 then begin writeln('0 1 1'); halt; end;
  f[0] := 0;
  f[1] := 1;
  for i:=2 to 1000 do
    begin
      f[i] := f[i-1] + f[i-2];
      if f[i]=a then break;
    end;
  writeln(f[i-2],' ',f[i-2],' ',f[i-3]);
end.
