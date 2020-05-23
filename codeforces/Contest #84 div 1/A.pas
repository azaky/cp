const
  z:array[0..17] of longint = (1,0,0,0,1,0,0,1,1,0,0,1,1,0,1,1,1,0);
  x:array[0..17] of longint = (0,0,0,0,4,0,0,7,44,0,0,47,444,0,77,447,4444,0);

var
  n,i,j:longint;

begin
  readln(n);
  if n<18 then
    begin
	  if z[n]=1 then writeln(x[n])
	    else writeln(-1);
	  halt;
	end;
  for i:=0 to 1000 do
    if (n-4*i) mod 7=0 then
	  begin
	    for j:=1 to i do write(4);
		for j:=1 to (n-4*i) div 7 do write(7);
		writeln; halt;
	  end;
end.
