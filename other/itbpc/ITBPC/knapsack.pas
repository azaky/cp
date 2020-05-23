var
  i, berat, hasil:longint;
  b,h:array[1..3] of longint;

procedure knapsack(bi,hi:longint);
  var
    loop:byte;

  begin
    if (bi > berat) then
      else if (bi = berat) then
        if hasil<hi then hasil:=hi
        else
      else for loop:=1 to 3 do knapsack(bi+b[loop],hi+h[loop]);
    end;

begin
  for i:=1 to 3 do readln(b[i],h[i]);
  readln(berat);
  hasil:=-1;
  knapsack(0,0);
  writeln(hasil);
end.
