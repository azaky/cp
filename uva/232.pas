var
  tc,i,j,k,r,c,n,down,across:longint;
  a,init:array[0..11,0..11] of char;
  num:array[1..10,1..10] of longint;
  d,ac:array[1..100,1..2] of longint;

begin
  tc:=0;
  for i:=0 to 11 do
    for j:=0 to 11 do
	  init[i,j]:='*';
  repeat
    read(r); if r=0 then break else readln(c); inc(tc); if tc>1 then writeln; a:=init;
	for i:=1 to r do
	  begin
	    for j:=1 to c do read(a[i,j]); readln;
	  end;
	fillchar(num,sizeof(num),255); n:=0; down:=0; across:=0;
	for i:=1 to r do
	  for j:=1 to c do
	    if ((a[i-1,j]='*') or (a[i,j-1]='*')) and (a[i,j]<>'*') then
		  begin
		    inc(n); num[i,j]:=n;
			if a[i-1,j]='*' then
			  begin
			    inc(down); d[down][1]:=i; d[down][2]:=j;
			  end;
			if a[i,j-1]='*' then
			  begin
			    inc(across); ac[across][1]:=i; ac[across][2]:=j;
			  end;
		  end;
	writeln('puzzle #',tc,':');
	writeln('Across');
	for k:=1 to across do
	  begin
	    write(num[ac[k,1],ac[k,2]]:3,'.');
		i:=ac[k,1]; j:=ac[k,2];
		repeat
		  write(a[i,j]); inc(j);
		until a[i,j]='*'; writeln;
	  end;
	writeln('Down');
	for k:=1 to down do
	  begin
	    write(num[d[k,1],d[k,2]]:3,'.');
		i:=d[k,1]; j:=d[k,2];
		repeat
		  write(a[i,j]); inc(i);
		until a[i,j]='*'; writeln;
	  end;
  until false;
end.
