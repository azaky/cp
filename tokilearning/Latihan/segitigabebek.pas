const
  ep = 1e-9;

var
  n,i,j,k:longint;
  ans,area:extended;
  doub:boolean;
  x,y:array[1..300] of extended;

begin
  readln(n);
  for i:=1 to n do readln(x[i],y[i]);
  ans:=1e51; doub:=false;
  for i:=1 to n-2 do
    for j:=i+1 to n-1 do
	  for k:=j+1 to n do
	    begin
		  area:=abs(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-x[k]*y[j]-x[j]*y[i]-x[i]*y[k])/2;
		  if (area<ep) or (area>ans) then continue;
		  if (abs(area-ans)<ep) then doub:=true
		    else
			  begin
			    ans:=area; doub:=false;
			  end;
		end;
  if doub or (ans>1e50) then writeln('-1.00')
    else writeln(ans:0:2);
end.
