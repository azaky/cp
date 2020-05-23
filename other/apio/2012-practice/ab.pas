var
  ka,kb,k,i,j,kans:longint;
  da,la,db,lb,a,b,l,lans,d:array[0..100000] of int64;
  p,carry:int64;

begin
  readln(ka);
  for i:=1 to ka do readln(da[i],la[i]);
  readln(kb);
  for i:=1 to kb do readln(db[i],lb[i]);
  la[0] := high(int64); lb[0] := high(int64);
  k := 0; p := 0;
  while (ka>0) or (kb>0) do
    begin
      if la[ka]=lb[kb] then
        begin
          p := p + la[ka];
          inc(k);
          a[k] := da[ka]; b[k] := db[kb]; l[k] := la[ka];
          dec(ka); dec(kb);
        end
      else if la[ka]<lb[kb] then
        begin
          p := p + la[ka];
          inc(k);
          a[k] := da[ka]; b[k] := db[kb]; l[k] := la[ka];
          lb[kb] := lb[kb] - la[ka]; dec(ka);
        end
      else if lb[kb]<la[ka] then
        begin
          p := p + lb[kb];
          inc(k);
          a[k] := da[ka]; b[k] := db[kb]; l[k] := lb[kb];
          la[ka] := la[ka] - lb[kb]; dec(kb);
        end;
    end;
  d[0] := -1;
  for i:=1 to k do
    begin
      inc(kans);
      d[kans] := (a[i]+b[i]+carry) mod 10; lans[kans] := 1;
      if d[kans]=d[kans-1] then
        begin
          dec(kans);
          inc(lans[kans],1);
        end;
      carry := (a[i]+b[i]+carry) div 10;
      if l[i]=1 then continue;
      inc(kans);
      d[kans] := (a[i]+b[i]+carry) mod 10; lans[kans] := l[i]-1;
      if d[kans]=d[kans-1] then
        begin
          dec(kans);
          inc(lans[kans],l[i]-1);
        end;
    end;
  if carry>0 then
    begin
      inc(kans);
      d[kans] := 1; lans[kans] := 1;
      if d[kans]=d[kans-1] then
        begin
          dec(kans); inc(lans[kans],1);
        end;
    end;
  writeln(kans);
  for i:=kans downto 1 do writeln(d[i],' ',lans[i]);
end.
