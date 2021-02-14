var
  n,i,q,t,a,b,mid:longint;
  x:array[0..100001] of longint;

begin
  readln(n);
  for i:=1 to n do
    begin
	  readln(x[i]); x[i]:=x[i]+x[i-1];
	end;
  readln(q);
  if n=1 then
    begin
	  for i:=1 to q do writeln(1);
	  halt;
	end;
  for i:=1 to q do
    begin
	  readln(t);
	  a:=0; b:=n;
	  repeat
	    if (b-a)=1 then break else mid:=(a+b) div 2;
		if x[mid]<t then a:=mid
		  else b:=mid;
	  until false;
	  writeln(b);
	end;
end.
