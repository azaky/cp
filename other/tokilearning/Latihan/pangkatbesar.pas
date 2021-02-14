const
  max = 1000000;

var
  i:longint;
  a,b,temp:int64;

function power(a,b:int64):int64;
  begin
    if b=0 then exit(1) else power:=sqr(power(a,b div 2)) mod max;
	if b mod 2=1 then power:=(power*a) mod max;
  end;
  
begin
  readln(a,b); temp:=power(a,b);
  if b*ln(a)/ln(10)>=6 then
    if temp=0 then write('00000')
	  else for i:=1 to 5-trunc(ln(temp)/ln(10)) do write('0');
  writeln(temp);
end.
