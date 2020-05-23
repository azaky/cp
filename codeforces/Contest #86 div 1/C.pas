const
  max = trunc(sqrt(3e8));

var
  l,r,lim,n,i,j,t,np,x,y,si:longint;
  used:array[1..300000000] of boolean;
  prime:array[1..max] of boolean;
  p:array[1..max] of longint;
  gcd:array[0..max,0..max] of longint;

function isprime(a:longint):boolean;
  var
    i:longint;
  
  begin
    if a<=max then exit(prime[a]);
    for i:=1 to np do
	  if (a mod p[i]=0) then exit(false);
	exit(true);
  end;

begin
  fillchar(prime,sizeof(prime),true);
  np:=0; prime[1]:=false;
  for i:=2 to trunc(sqrt(max)) do
    if prime[i] then
	  for j:=2 to max div i do prime[i*j]:=false;
  for i:=2 to max do
    if prime[i] then
	  begin
	    inc(np); p[np]:=i;
	  end;
  writeln(max,' ',np);halt;
  for i:=1 to max do
    begin
	  gcd[i,0]:=i; gcd[0,i]:=i; gcd[i,i]:=i;
	end;
  for i:=1 to max do
    for j:=i+1 to max do gcd[i,j]:=gcd[j mod i,i];
  
  readln(l,r); lim:=trunc(sqrt(r-1));
  n:=0;
  for i:=1 to lim do
    begin
	  si:=sqr(i);
	  if l<si then x:=1
	    else x:=trunc(sqrt(l-i)); if sqr(x)+i<l then inc(x);
	  y:=trunc(sqrt(r-si));
	  for j:=x to y do
	    begin
		  t:=si+sqr(j);
		  if used[t] then continue else used[t]:=true;
		  if (gcd[i,j]=1) then
		    if isprime(t) then inc(n);
		end;
	end;
  writeln(n);
end.
