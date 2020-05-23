var
  nprime,i,j,t,k:longint;
  d,prime:array[1..100000] of longint;

function isprime(a:longint):boolean;
  var
    i:longint;
  
  begin
    if a=1 then exit(false);
	if a<4 then exit(true);
	for i:=2 to trunc(sqrt(a)) do
	  if a mod i=0 then exit(false);
	exit(true);
  end;

function gcd(a,b:longint):longint;
  begin
    if a=0 then exit(b)
	  else exit(gcd(b mod a,a));
  end;

begin
  d[1]:=1; nprime:=0;
  for i:=2 to 100000 do
    begin
	  for j:=1 to nprime+1 do
	    if j>nprime then
		  begin
		    inc(nprime); prime[nprime]:=i; d[i]:=2;
		  end
		else if i mod prime[j]=0 then
		  begin
		    t:=i; k:=0;
			while t mod prime[j]=0 do
			  begin
			    t:=t div prime[j]; inc(k);
			  end;
			d[i]:=d[t]*(k+1); break;
		  end;
	end;
  writeln('done');{
  readln(n);
  for i:=1 to n do readln(x[i],y[i]);
  }
end.
