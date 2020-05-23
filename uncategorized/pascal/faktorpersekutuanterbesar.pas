var
  t,i:integer;
  a,b:int64;

function gcd(a,b:int64):int64;
  begin
    if b=0 then exit(a)
      else exit(gcd(b,a mod b));
  end;

begin
  readln(t);
  for i:=1 to t do
    begin
      readln(a,b);
      if (a=0) or (b=0) then writeln(a+b)
        else writeln(gcd(a,b));
    end;
end.
