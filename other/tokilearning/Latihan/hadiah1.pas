var
  n,m,i:longint;
  best,a:int64;
  sum:array[0..100000] of int64;

begin
  readln(n,m);
  for i:=1 to n do
    begin
	  read(a); sum[i]:=sum[i-1]+a;
	end;
  best:=round(-1e18);
  for i:=m to n do
    if sum[i]-sum[i-m]>best then best:=sum[i]-sum[i-m];
  writeln(best);
end.
