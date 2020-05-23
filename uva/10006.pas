const
  c:array[1..15] of longint = (561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973);

var
  n,i:longint;

begin
  repeat
    readln(n); if n=0 then halt;
    for i:=1 to 16 do
      if i=16 then writeln(n,' is normal.')
        else if c[i]=n then
          begin
            writeln('The number ',n,' is a Carmichael number.');break;
          end;
  until false;
end.
