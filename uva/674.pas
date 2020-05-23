const
  a:array[1..5] of longint = (50,25,10,5,1);

var
  i,j,n:longint;
  way:array[0..7489] of int64;

begin
  way[0]:=1;
  for i:=1 to 5 do
    for j:=a[i] to 7489 do
	  way[j]:=way[j]+way[j-a[i]];
  repeat
    readln(n); writeln(way[n]);
  until eof;
end.
