const
  maxn = 60000;

var
  np,t,p,i,j,n:longint;
  sigma,prime:array[0..maxn] of longint;

begin
  sigma[1]:=1; np:=0;
  for i:=2 to maxn do
    begin
	  t:=i; sigma[i]:=1;
	  for j:=1 to np+1 do
	    begin
		  if j>np then
		    begin
			  inc(np); prime[np]:=i;
			  sigma[i]:=i+1; break;
			end;
		  if t mod prime[j]<>0 then continue else p:=1;
		  while t mod prime[j]=0 do
		    begin
			  t:=t div prime[j];
			  p:=p*prime[j];
			  sigma[i]:=sigma[i]+p;
			end;
		  sigma[i]:=sigma[t]*sigma[i]; break;
		end;
	end;
  writeln('PERFECTION OUTPUT');
  repeat
    read(n); if n=0 then break else write(n:5,'  ');
	if sigma[n]=2*n then writeln('PERFECT')
	  else if sigma[n]<2*n then writeln('DEFICIENT')
	    else writeln('ABUNDANT');
  until false;
  writeln('END OF OUTPUT');
end.
//00:10:29:594