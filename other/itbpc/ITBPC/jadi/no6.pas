var
  b,h:array[1..3] of longint;
  i,x1,x2,temp,berat,hasil,harga:longint;

begin
  for i:=1 to 3 do readln(b[i],h[i]);
  readln(berat);
  hasil:=-1;
  for x1:=0 to (berat div b[1]) do
    for x2:=0 to ((berat-x1*b[1]) div b[2]) do
      begin
        temp:=berat-x1*b[1]-x2*b[2];
        if temp mod b[3] = 0 then
          begin
            harga:=x1*h[1]+x2*h[2]+(temp div b[3])*h[3];
            if harga>hasil then hasil:=harga;
          end;
      end;
  writeln(hasil);
end.