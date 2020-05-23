var
  a,n:longint;

function gcd(a,b:longint):longint;
  begin
    if a=0 then gcd:=b
      else gcd:=gcd(b mod a,a);
  end;

function phi(n:longint):longint;
  var
    i:longint;

  begin
    phi:=0;
    if n=1 then phi:=1
      else for i:=1 to n-1 do
        if gcd(i,n)=1 then inc(phi);
  end;

begin
  readln(n);
  writeln(phi(n));
end.
