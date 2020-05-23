var
  b,p,m:int64;

function power(b,p,m:int64):int64;
  var
    temp:int64;
  
  begin
    if (m=1) then exit(0)
	  else if (p=0) then exit(1)
	    else if (b<2) then exit(b);
    temp:=sqr(power(b,p div 2,m)) mod m;
	if p mod 2=1 then exit((temp*b) mod m)
	  else exit(temp);
  end;

begin
  while not eof do
    begin
	  readln(b); readln(p); readln(m); readln;
	  writeln(power(b,p,m));
	end;
end.
