var
  a,b,ta,tb,car,s:longint;

begin
  repeat
    readln(a,b); if (a=0) and (b=0) then break else car:=0; s:=0;
	while (a>0) or (b>0) do
	  begin
	    ta:=a mod 10; tb:=b mod 10;
		if ta+tb+s>=10 then
		  begin
		    s:=1; inc(car);
		  end
		else s:=0;
		a:=a div 10; b:=b div 10;
	  end;
	if car=0 then writeln('No carry operation.')
	  else if car=1 then writeln('1 carry operation.')
	    else writeln(car,' carry operations.');
  until false;
end.
