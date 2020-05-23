var
  a,n:integer;

function gcd(a,b:integer):integer;
  begin
    if a=0 then gcd:=b
      else gcd:=gcd(b mod a,a);
  end;

function phi(n:integer):integer;
  var
    i:integer;

  begin
    phi:=0;
    if n=1 then phi:=1
      else for i:=1 to n-1 do
        if gcd(i,n)=1 then inc(phi);
  end;

function powermod(a,pangkat,modulo:integer):integer;
  var
    temp:integer;

  begin
    if pangkat=0 then powermod:=1
      else if pangkat=1 then powermod:=a mod modulo
        else
          begin
            temp:=powermod(a,pangkat div 2,modulo);
            if pangkat mod 2 = 0 then powermod:=(temp*temp) mod modulo
              else powermod:=(temp*temp*a) mod modulo;
          end;
  end;

begin
  readln(a,n);
  writeln(powermod(a,phi(n),n));
end.
