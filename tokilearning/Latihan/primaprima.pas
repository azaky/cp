const
  maxn = 10001;
  ten : array[0..6] of int64 = (1,10,100,1000,10000,100000,1000000);

var
  i,j,iprime,a,b,m,n,ans:longint;
  num:int64;
  prime:array[1..maxn] of boolean;
  map:array[1..maxn] of longint;
  p:array[1..maxn] of int64;
  arr:array[1..1000,1..2] of longint;

function pprime(a:int64):boolean;
  var
    i:longint;
  
  begin
    if a=1 then exit(false)
	  else if a<4 then exit(true);
	pprime:=true;
	for i:=2 to trunc(sqrt(a)) do
	  if a mod i=0 then exit(false);
  end;

begin
  fillchar(prime,sizeof(prime),true);
  prime[1]:=false;
  for i:=1 to trunc(sqrt(maxn)) do
    if prime[i] then
	  for j:=2 to maxn div i do
	    prime[i*j]:=false;
  iprime:=0;
  for i:=2 to maxn-3 do
    if prime[i] then
	  begin
	    inc(iprime);
		p[iprime]:=i; map[i]:=iprime;
	  end;
  readln(m,n);
  a:=-1; b:=-1;
  for i:=m to n do
    if prime[i] then
	  begin
	    a:=map[i]; break;
	  end;
  for i:=n downto m do
    if prime[i] then
	  begin
	    b:=map[i]; break;
	  end;
  if a<0 then
    begin
	  writeln('TIDAK ADA'); halt;
	end
  else ans:=0;
  for i:=a to b do
    for j:=a to b do
	  begin
	    if (i=j) or ((p[i]+p[j]) mod 3=0) then continue;
		num:=p[i]*ten[trunc(ln(p[j])/ln(10))+1]+p[j];
		if pprime(num) then
		  begin
		    inc(ans); arr[ans][1]:=i; arr[ans][2]:=j;
		  end;
	  end;
  for i:=1 to ans do
    writeln(p[arr[i][1]],' ',p[arr[i][2]]);
  if ans=0 then writeln('TIDAK ADA');
end.
