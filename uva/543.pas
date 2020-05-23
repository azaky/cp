const
  maxn = 1000000;

var
  i,j,n,k:longint;
  prime:array[1..1000000] of boolean;
  p:array[1..100000] of longint;

begin
  fillchar(prime,sizeof(prime),true); prime[1]:=false;
  for i:=2 to 997 do
    if prime[i] then
	  for j:=2 to maxn div i do prime[i*j]:=false;
  n:=0;
  for i:=1 to maxn do
    if prime[i] then
	  begin
	    inc(n); p[n]:=i;
	  end;
  repeat
    readln(n); if n=0 then break;
	k:=2;
	while not prime[n-p[k]] do inc(k);
	writeln(n,' = ',p[k],' + ',n-p[k]);
  until false;
end.
