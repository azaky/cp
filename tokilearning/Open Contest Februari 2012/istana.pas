const
  mnum:array[1..12] of int64 = (31,28,31,30,31,30,31,31,30,31,30,31);
  mname:array[1..12] of string = ('Januari','Februari','Maret','April','Mei','Juni','Juli','Agustus','September','Oktober','November','Desember');
  day:array[0..4] of string = ('Jumat','Senin','Selasa','Rabu','Kamis');

var
  n,d,m,y,mcur,dd:int64;

begin
  readln(n); dec(n);
  write(day[(1+(n mod 5)) mod 5],', ');
  dd:=1; d:=1; m:=1;
  //y:=2013;
  y:=2013 + 28*(n div 7305); n:=n mod 7305;
  while n>0 do
    begin
      mcur:=mnum[m];
      if (m=2) and (y mod 4=0) then inc(mcur);
      inc(d); dd:=(dd+1) mod 7;
      if d>mcur then
        begin
          d:=1; inc(m);
        end;
      if m>12 then
        begin
          m:=1; inc(y);
        end;
      if not (dd in [6,0]) then dec(n);
    end;
  writeln(d,' ',mname[m],' ',y);
end.
