var
  n,i,sum,ans,tc:longint;
  a:array[1..50] of longint;

begin
  tc:=0;
  repeat
    read(n); if n=0 then break else sum:=0; ans:=0; inc(tc);
	for i:=1 to n do begin read(a[i]); inc(sum,a[i]); end; sum:=sum div n;
	for i:=1 to n do
	  if a[i]>sum then inc(ans,a[i]-sum);
	writeln('Set #',tc);
	writeln('The minimum number of moves is ',ans,'.');
	writeln;
  until false;
end.
