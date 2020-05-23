var
  n,i,j,row,col,s,r,c:longint;
  a:array[0..101,0..101] of longint;

begin
  repeat
    readln(n); if n=0 then break;
	for i:=1 to n do
	  for j:=1 to n do read(a[i,j]);
	row:=0; col:=0;
	for i:=1 to n do
	  begin
	    s:=0;
		for j:=1 to n do s:=(s+a[i,j]) mod 2;
		if s=1 then
		  begin
		    inc(row); r:=i;
		  end;
	  end;
	for j:=1 to n do
	  begin
	    s:=0;
		for i:=1 to n do s:=(s+a[i,j]) mod 2;
		if s=1 then
		  begin
		    inc(col); c:=j;
		  end;
	  end;
	if (row=0) and (col=0) then writeln('OK')
	  else if (row=1) and (col=1) then writeln('Change bit (',r,',',c,')')
	    else writeln('Corrupt');
  until false;
end.
