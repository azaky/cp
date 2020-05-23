const
  a:array[1..11] of longint = (10000,5000,2000,1000,500,200,100,50,20,10,5);

var
  i,j:longint;
  n:extended;
  way:array[0..30000] of int64;

begin
  way[0]:=1;
  for i:=1 to 11 do
    for j:=a[i] to 30000 do way[j]:=way[j]+way[j-a[i]];
  repeat
    readln(n); if n=0 then break;
	write(n:6:2); writeln(way[round(100*n)]:17);
  until false;
end.
