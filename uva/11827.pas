var
  n,i,t,m,max,j,z:longint;
  s:ansistring;
  a:array[1..100] of longint;

function gcd(a,b:longint):longint;
  begin
    if a=0 then exit(b)
	  else exit(gcd(b mod a,a));
  end;

begin
  readln(n);
  for z:=1 to n do
    begin
	  readln(s);
	  t:=0; m:=0;
	  for i:=1 to length(s) do
		if s[i]=' ' then
		  begin
		    inc(m); a[m]:=t; t:=0;
		  end
	    else t:=10*t+ord(s[i])-ord('0');
	  if s[length(s)]<>' ' then
	    begin
		  inc(m); a[m]:=t;
		end;
	  max:=0;
	  for i:=1 to m-1 do
	    for j:=i+1 to m do
		  begin
		    t:=gcd(a[i],a[j]);
			if t>max then max:=t;
		  end;
	  writeln(max);
	end;
end.