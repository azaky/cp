//1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p)
const
  p:array[1..8] of longint = (1,2,5,10,20,50,100,200);
var
  i,j:longint;
  way:array[0..200] of longint;

begin
  way[0]:=1;
  for i:=1 to 8 do
    for j:=p[i] to 200 do 
      if way[j-p[i]]>0 then way[j]:=way[j]+way[j-p[i]];
  for i:=1 to 10 do writeln(i:5,way[i]:10);
  writeln(way[200]);
end.
