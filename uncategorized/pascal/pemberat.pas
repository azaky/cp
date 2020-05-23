var
  bebek,kucing,n,pemberat:int64;
  l,i:integer;

begin
  readln(bebek);
  readln(kucing);
  n:=kucing-bebek;
  l:=trunc(ln(n)/ln(2));
  pemberat:=1;
  for i:=1 to l do pemberat:=pemberat*2;
  while n>0 do
    begin
      while pemberat>n do pemberat:=pemberat div 2;
      writeln(pemberat);
      n:=n-pemberat;
    end;
end.