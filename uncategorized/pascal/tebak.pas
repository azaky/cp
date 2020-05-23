var
  a,b,m:integer;
  hasil:string;
  
begin
  readln(a,b);
  while true do
    begin
      m:=(a+b) div 2;
      writeln(m);
      flush(output);
      readln(hasil);
      if hasil='selamat' then break
        else if hasil='terlalu kecil' then a:=m
          else b:=m;
    end;
end.