const
  maxn = 50000;

var
  i,p,lim:longint;
  phi:array[1..maxn] of longint;
  ans:array[1..maxn] of int64;

begin
  phi[1]:=1; ans[1]:=1;
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
  for i:=2 to maxn do ans[i]:=ans[i-1]+2*phi[i];
  repeat
    readln(i); if i=0 then halt else writeln(ans[i]);
  until false;
end.
