const
  maxn = 1000000000;

var
  n:longint;

function phi(n:longint):longint;
  var
    p,lim:longint;

  begin
    p:=2;
    phi:=n;
    while n>1 do
      begin
	    lim:=trunc(sqrt(n));
        while (n mod p <> 0) and (p<=lim) do inc(p);
		if p>lim then exit((phi div n)*(n-1));
        phi:=(phi div p)*(p-1);
        while n mod p = 0 do n:=n div p;
      end;
  end;

begin
  repeat
    readln(n);
	if n=0 then break
	  else if n=1 then writeln(0)
	    else writeln(phi(n));
  until false;
end.
