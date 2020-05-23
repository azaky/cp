var
  n,z,i,j,x,o,linex,lineo:longint;
  a:array[1..3] of string[3];

begin
  readln(n);
  for z:=1 to n do
    begin
	  for i:=1 to 3 do readln(a[i]); if z<n then readln;
	  x:=0; o:=0;
	  for i:=1 to 3 do
	    for j:=1 to 3 do
		  case a[i,j] of
		    'X':inc(x);
			'O':inc(o);
		  end;
	  if (x<>o) and (x-o<>1) then
	    begin
		  writeln('no');
		  continue;
		end;

	  linex:=0; lineo:=0;
	  if (a[1,1]=a[1,2]) and (a[1,2]=a[1,3]) then
	    if a[1,1]='X' then inc(linex) else if a[1,1]='O' then inc(lineo);
	  if (a[2,1]=a[2,2]) and (a[2,2]=a[2,3]) then
	    if a[2,1]='X' then inc(linex) else if a[2,1]='O' then inc(lineo);
	  if (a[3,1]=a[3,2]) and (a[3,2]=a[3,3]) then
	    if a[3,1]='X' then inc(linex) else if a[3,1]='O' then inc(lineo);
		
	  if (a[1,1]=a[2,1]) and (a[2,1]=a[3,1]) then
	    if a[1,1]='X' then inc(linex) else if a[1,1]='O' then inc(lineo);
	  if (a[1,2]=a[2,2]) and (a[2,2]=a[3,2]) then
	    if a[1,2]='X' then inc(linex) else if a[1,2]='O' then inc(lineo);
	  if (a[1,3]=a[2,3]) and (a[2,3]=a[3,3]) then
	    if a[1,3]='X' then inc(linex) else if a[1,3]='O' then inc(lineo);
		
	  if (a[1,1]=a[2,2]) and (a[2,2]=a[3,3]) then
	    if a[1,1]='X' then inc(linex) else if a[1,1]='O' then inc(lineo);
	  if (a[1,3]=a[2,2]) and (a[2,2]=a[3,1]) then
	    if a[1,3]='X' then inc(linex) else if a[1,3]='O' then inc(lineo);
		
	  if ((linex>0) and (lineo>0)) then
	    begin
		  writeln('no');
		  continue;
		end;
	  if ((lineo=1) and (o<>x)) or ((linex>0) and (o=x)) then
	    begin
		  writeln('no');
		  continue;
		end;
	  writeln('yes');
	end;
end.
