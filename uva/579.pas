var
  clock:string;
  p,h,m:integer;
  t:extended;

begin
  repeat
    readln(clock); if clock='0:00' then break;
	p:=pos(':',clock);
	val(copy(clock,1,p-1),h);
	val(copy(clock,p+1,length(clock)-p),m);
	t:=abs(30*h-5.5*m);
	if t>180 then t:=360-t;
	writeln(t:0:3);
  until false;
end.
//00:05:22.116