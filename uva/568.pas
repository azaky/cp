var
  n,t,a,ans,i:longint;

begin
  repeat
    readln(n);
	if n=0 then
	  begin
	    writeln('    0 -> 1');
		continue;
	  end
	else 
	t:=n; a:=0;
	while t>0 do
	  begin
	    t:=t div 5; inc(a,t);
	  end;
	ans:=1;
	for i:=1 to n do
	  begin
	    t:=i; while t mod 5=0 do t:=t div 5;
		while (t mod 2=0) and (a>0) do
		  begin
		    t:=t div 2; dec(a);
		  end;
		ans:=(ans*t) mod 10;
	  end;
	writeln(n:5,' -> ',ans);
  until eof;
end.
