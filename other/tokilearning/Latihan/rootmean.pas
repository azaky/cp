var
  n,i,step:longint;
  l,r,a,b,c,d,e,sa,sb,sc,sd,se,ans,rmans,min:extended;
  num:array[1..50000] of extended;

function rms(a:extended):extended;
  var
    i:longint;
	
  begin
    rms:=0;
	for i:=1 to n do rms:=rms+abs(num[i]-a)*sqrt(abs(num[i]-a));
  end;

begin
  readln(n); l:=1e100; r:=1e-100;
  for i:=1 to n do
    begin
	  readln(num[i]);
	  if num[i]<l then l:=num[i];
	  if num[i]>r then r:=num[i];
	end;
  ans:=(l+r)/2; rmans:=rms(ans);
  for step:=1 to 100 do
    begin
	  if l=r then break;
	  a:=l; e:=r; c:=(a+e)/2; b:=(a+c)/2; d:=(c+e)/2;
	  sa:=rms(a); sb:=rms(b); sc:=rms(c); sd:=rms(d); se:=rms(e);
	  //writeln(a:8:4,' ',b:8:4,' ',c:8:4,' ',d:8:4,' ',e:8:4);
	  //writeln(sa:8:4,' ',sb:8:4,' ',sc:8:4,' ',sd:8:4,' ',se:8:4);
	  //writeln;
	  min:=sc; l:=b; r:=d; if sc<rmans then begin ans:=c; rmans:=sc; end;
	  {
	  if sa<min then
	    begin
		  min:=sa; l:=a; r:=c; if sa<rmans then begin ans:=a; rmans:=sa; end;
		end;
	  }
	  if sb<min then
	    begin
		  min:=sb; l:=a; r:=c; if sb<rmans then begin ans:=b; rmans:=sb; end;
		end;
	  if sd<min then
	    begin
		  min:=sd; l:=c; r:=e; if sd<rmans then begin ans:=d; rmans:=sd; end;
		end;
	  {
	  if se<min then
	    begin
		  min:=se; l:=c; r:=e; if se<rmans then begin ans:=e; rmans:=se; end;
		end;
	  }
	end;
  writeln(ans:0:2);
end.
