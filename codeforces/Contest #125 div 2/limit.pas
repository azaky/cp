var
  n,m,i,d:longint;
  a,b:array[0..111] of longint;

function gcd(a,b:longint):longint;
  begin
    if a mod b = 0 then exit(b)
    else exit(gcd(b,a mod b));
  end;

begin
  readln(n,m);
  for i:=0 to n do read(a[i]);
  for i:=0 to m do read(b[i]);
  if n>m then
    begin
      if a[0]*b[0]<0 then writeln('-Infinity') else writeln('Infinity');
      halt;
    end;
  if n<m then
    begin
      writeln('0/1');
      halt;
    end;
  if a[0]*b[0]<0 then write('-');
  a[0] := abs(a[0]); b[0] := abs(b[0]); d := gcd(a[0],b[0]);
  writeln(a[0] div d,'/',b[0] div d);
end.
