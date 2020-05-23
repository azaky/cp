var
  n, i, j, trol : longint;
  berat, barang : array[1..100] of longint;
  ks : array[1..100, 1..100] of longint;


function maks(a, b : longint) : longint;

begin
  maks := a;
  if (b > a) then
    maks := b;
end;



function knapsack(sisa, pos : longint) : longint;

begin
  if (sisa = 0) then
    knapsack := 0
  else
  if (sisa < 0) or (pos = 0) then
    knapsack := -100000
  else begin
    ks[sisa,pos] := maks(barang[pos] + knapsack(sisa-berat[pos], pos-1),
                         knapsack(sisa,pos-1));
    knapsack := ks[sisa,pos];
  end;

  //writeln(knapsack,' -- sisa = ',sisa,'  pos = ',pos);
end;





begin
  readln(n, trol);
  for i:= 1 to n do
    readln(berat[i], barang[i]);


  writeln(knapsack(trol,n));

  writeln;

  for i := 1 to trol do begin
    for j := 1 to n do
      write(ks[i,j]:7);
    writeln;
  end;

end.
