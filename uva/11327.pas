const
  maxn = 200000;

var
  i,p,lim,n:longint;
  k:int64;
  phi:array[1..maxn] of longint;
  sum:array[0..maxn] of int64;
  prime:array[1..maxn] of boolean;

function search(k:int64):longint;
  var
    l,r,mid:longint;
  
  begin
    l:=1; r:=maxn;
	repeat
	  mid:=(l+r) div 2;
	  if (k>sum[mid-1]) and (k<=sum[mid]) then exit(mid)
	    else if k>sum[mid] then l:=mid+1
		  else r:=mid;
    until false;
  end;

function gcd(a,b:longint):longint;
  begin
    if a=0 then exit(b)
	  else exit(gcd(b mod a,a));
  end;

function loc(a,n:longint):longint;
  var
    k,i:longint;
  
  begin
    if prime[n] then exit(a) else k:=0;
	for i:=1 to n do
	  if gcd(i,n)=1 then
	    begin
		  inc(k);
		  if k=a then exit(i);
		end;
  end;

begin
  phi[1]:=1;
  for i:=2 to maxn do
    begin
	  if i mod 2=0 then
	    begin
		  if i mod 4=0 then phi[i]:=phi[i div 2]*2
		    else phi[i]:=phi[i div 2];
		  continue;
		end;
	  p:=3; lim:=trunc(sqrt(i));
	  while (p<=lim) and (i mod p<>0) do inc(p,2);
	  if p>lim then
	    begin
		  phi[i]:=i-1;
		  continue;
		end;
	  if i mod (p*p)=0 then phi[i]:=phi[i div p]*p
	    else phi[i]:=phi[i div p]*(p-1);
	end;
  for i:=1 to maxn do sum[i]:=sum[i-1]+phi[i];
  for i:=1 to maxn do if phi[i]=i-1 then prime[i]:=true else prime[i]:=false;
  repeat
    readln(k); if k=0 then halt;
	if k=1 then
	  begin
	    writeln('0/1'); continue;
	  end
	else dec(k); n:=search(k);
	writeln(loc(k-sum[n-1],n),'/',n);
  until false;
end.
