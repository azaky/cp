var
  a,b,c,d,e,f,t:int64;

function gcd(a,b:int64):int64;
  begin
    if b=0 then exit(a)
      else exit(gcd(b,a mod b));
  end;

begin
  readln(a,b); readln(c,d);
  t:=gcd(a,b); a:=a div t; b:=b div t;
  t:=gcd(c,d); c:=c div t; d:=d div t;
  t:=gcd(b,d);
  writeln(a*(d div t)+c*(b div t),' ',(b div t)*d);
  //e:=a*d+b*c; f:=b*d; t:=gcd(e,f);
  //writeln(e div t,' ',f div t);
end.

