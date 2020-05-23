var
  t,kasus:integer;
  a,b,n,m,n1,n2,m1,m2,summ,sumn:int64;

function gcd(a,b:longint):longint;
  begin
    if b=0 then gcd:=a
      else if a<b then gcd:=gcd(b,a)
        else gcd:=gcd(b,a mod b);
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(a,b,n,m);
      n1:=(a div n)*n;
      if a mod n<>0 then n1:=n1+n;
      n2:=(b div n)*n;
      m:=(n*m) div gcd(n,m);
      m1:=(a div m)*m;
      if a mod m<>0 then m1:=m1+m;
      m2:=(b div m)*m;
      sumn:=((n1+n2)*((n2-n1+n) div n)) div 2;
      summ:=((m1+m2)*((m2-m1+m) div m)) div 2;
      writeln(sumn-summ);
    end;
end.
