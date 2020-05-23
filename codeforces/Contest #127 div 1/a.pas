var
  n,x:longint;

begin
  readln(x);
  if x = 3 then begin writeln(5); halt; end;
  if x mod 2=0 then
    begin
      for n := 1 to 1000 do
        if n mod 2 = 0 then continue
          else if (sqr(n) div 2) >= x then break;
      writeln(n); halt;
    end;
  if x mod 2=1 then
    begin
      for n := 1 to 1000 do
        if n mod 2 = 0 then continue
          else if ((sqr(n)+1) div 2) >= x then break;
      writeln(n); halt;
    end;
end.
