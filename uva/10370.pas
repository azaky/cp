var
  kasus,c,n,sum,up,i:longint;
  avg:extended;
  a:array[1..1000] of longint;

begin
  readln(c);
  for kasus:=1 to c do
    begin
	  read(n); for i:=1 to n do read(a[i]);
	  sum:=0; for i:=1 to n do inc(sum,a[i]);
	  avg:=sum/n;
	  up:=0; for i:=1 to n do if a[i]>avg then inc(up);
	  writeln(100*up/n:0:3,'%');
	end;
end.
//00:02:36.181