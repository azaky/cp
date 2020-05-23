var
  n,i,t:longint;
  jolly:boolean;
  a:array[1..3000] of longint;
  d:array[1..3000] of boolean;

begin
  while not eof do
    begin
	  read(n); fillchar(d,sizeof(d),false);
	  for i:=1 to n do read(a[i]); readln;
	  jolly:=true;
	  for i:=1 to n-1 do
	    begin
		  t:=abs(a[i]-a[i+1]);
		  if t>=n then
		    begin
			  jolly:=false; break;
			end
	      else if d[t] then
		    begin
			  jolly:=false; break;
			end
		  else d[t]:=true;
		end;
	  if jolly then writeln('Jolly')
	    else writeln('Not jolly');
	end;
end.
