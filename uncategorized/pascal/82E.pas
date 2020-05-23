var
  n,i,j,k:longint;
  best,tx,ty,tz,max,ax,ay,az:extended;
  x,y,z:array[1..100] of extended;

begin
  readln(n);
  for i:=1 to n do readln(x[i],y[i],z[i]);
  best:=1e100;
  for i:=1 to n-1 do
    for j:=i+1 to n do
	  begin
	    tx:=(x[i]+x[j])/2;
		ty:=(y[i]+y[j])/2;
		tz:=(z[i]+z[j])/2;
		max:=0;
		for k:=1 to n do
		  if max<sqrt(sqr(tx-x[k])+sqr(ty-y[k])+sqr(tz-z[k])) then
		    max:=sqrt(sqr(tx-x[k])+sqr(ty-y[k])+sqr(tz-z[k]));
		if max<best then
		  begin
		    best:=max;
			ax:=tx; ay:=ty; az:=tz;
		  end;
	  end;
  writeln(ax:0:6,' ',ay:0:6,' ',az:0:6);
end.
