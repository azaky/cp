const
  maxn = 1000000;
  
var
  i,j,n:longint;
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
    readln(n); if n=0 then break else write(n,' : ');
	i:=1; j:=0;
	while n>1 do
	  begin
	    while n mod p[i]>0 do inc(i);
		inc(j);
		while n mod p[i]=0 do n:=n div p[i];
	  end;
	writeln(j);
  until false;
end.
