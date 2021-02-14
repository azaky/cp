const
  ep = 1e-11;

var
  n,i,k:longint;
  m,c:int64;
  a,b,mid,temp:extended;
  v:array[1..50000] of extended;

begin
  readln(n,m);
  a:=0; b:=0;
  for i:=1 to n do
    begin
	  read(v[i]);
	  if v[i]>b then b:=v[i];
	end;
  b:=2*b;
  while true do
    begin
	  mid:=(a+b)/2;
	  if b-a<1e-10 then break else c:=0;
	  for i:=1 to n do
	    begin
		  temp:=v[i]/mid;
		  if frac(temp)<ep then c:=c+trunc(temp)
		    else c:=c+trunc(temp)+1;
		  //c:=c+trunc(v[i]/mid)+1;
	      //if (v[i]/mid-trunc(v[i]/mid)<ep) then dec(c);
		end;
	  if c>m then a:=mid
	    else b:=mid;
	end;
  writeln(mid:0:10);
end.
