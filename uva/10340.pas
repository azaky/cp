var
  s,a,b:ansistring;
  p,l,i:longint;
  sub:boolean;

begin
  repeat
    readln(s); p:=pos(' ',s); a:=copy(s,1,p-1); b:=copy(s,p+1,length(s)-p);
	sub:=true; p:=1; l:=length(b);
	for i:=1 to length(a) do
	  begin
	    while (p<=l) and (b[p]<>a[i]) do inc(p);
		if p>l then
		  begin
		    sub:=false;
			break;
		  end
		else inc(p);
	  end;
	if sub then writeln('Yes') else writeln('No');
  until eof;
end.
