var
  i,j,n,k,nstat,na:longint;
  can:boolean;
  stat:array[1..1000] of longint;

begin
  repeat
    readln(n); if n=0 then break else
	repeat
	  read(k); if k=0 then break;
	  nstat:=0; na:=1; can:=true;
      for i:=1 to n-1 do
	    begin
		  if not can then
		    begin
			  read(k); continue;
			end;
		  if na<=k then
		    begin
			  for j:=na to k-1 do
			    begin
				  inc(nstat); stat[nstat]:=j;
				end;
			  na:=k+1;
			end
		  else if stat[nstat]=k then dec(nstat)
		    else can:=false;
		  read(k);
		end;
	  if can then writeln('Yes')
	    else writeln('No');
	until false;
	writeln;
  until false;
end.
