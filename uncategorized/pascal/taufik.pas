var
  a,b,c,temp : integer;
 
begin
  write('Masukkan tiga sisi segitiga : ');
  readln(a,b,c);
  //mengurutkan ketiga sisi
  if (b <= a) and (b <= c) then
    begin
      temp := a; a := b; b := temp;
    end;
  if (c <= a) and (c <= b) then
    begin
      temp := a; a := c; c := temp;
    end;
  if (c <= b) then
    begin
      temp := b; b := c; c := temp;
    end;
  //cek kalo bukan segitiga
  if (a+b <= c) then writeln('Segitiga tidak valid!')
  //cek segitiga lancip
  else if (a*a + b*b > c*c) then writeln('Segitiga Lancip!')
  //cek segitiga siku-siku
  else if (a*a + b*b = c*c) then writeln('Segitiga Siku-siku!')
  //cek segitiga tumpul
  else if (a*a + b*b < c*c) then writeln('Segitiga Tumpul!');
end.
