const
  maxn = 1000000000;

var
  n:longint;

function meyer(n:longint):longint;
  var
    p,phi,tau,lim,k:longint;
  
  begin
    p:=2; phi:=n; tau:=1; meyer:=n+1;
	while n>1 do
	  begin
	    lim:=trunc(sqrt(n));
		while (n mod p<>0) and (p<=lim) do
		  if p=2 then inc(p) else inc(p,2);
		if p>lim then p:=n;
		k:=0; phi:=(phi div p)*(p-1);
		while n mod p =0 do
		  begin
		    n:=n div p; inc(k);
		  end;
		tau:=tau*(k+1);
	  end;
	exit(meyer-tau-phi);
  end;

begin
  repeat
    readln(n); writeln(meyer(n));
  until eof;
end.
