var
  a,l,cyc,tc,ta:int64;

begin
  tc:=0;
  repeat
    readln(a,l); if (a<0) and (l<0) then break else cyc:=0; inc(tc); ta:=a;
	repeat
	  inc(cyc);
	  if a=1 then break
	    else if a mod 2=0 then a:=a div 2
		  else a:=3*a+1;
	until a>l;
	writeln('Case ',tc,': A = ',ta,', limit = ',l,', number of terms = ',cyc);
  until false;
end.
