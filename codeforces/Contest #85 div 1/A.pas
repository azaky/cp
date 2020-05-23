var
  n,i:longint;
  x,y,sum,sums:int64;
  a:array[1..100000] of int64;

begin
  readln(n,x,y);
  if y<n then
    begin
	  writeln(-1); halt;
	end;
  sum:=0; sums:=0;
  for i:=1 to n-1 do a[i]:=1;
  a[n]:=y-n+1;
  {
  for i:=1 to n do
    begin
	  a[i]:=y div n;
	  sum:=sum+a[i];
	end;
  for i:=1 to y-sum do inc(a[i]);
  }
  for i:=1 to n do sums:=sums+sqr(a[i]);
  if sums<x then writeln(-1)
    else for i:=1 to n do writeln(a[i]);
end.
