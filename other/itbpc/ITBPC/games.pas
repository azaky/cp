uses
  crt;

var
  baris,kolom,i,j,k,l,mines,temp,barisi,kolomi,v,vans,z,area:longint;
  input,temp1:string;
  bomb,stat,stat1:boolean;
  mine,hasil:array[0..1000,0..1000] of string;

procedure writemine(var baris,kolom:longint; stat2:boolean);
  var
    i,j:integer;

  begin
    for i:= 1 to baris do
      begin
        for j:=1 to kolom do
          if stat2=true then write(mine[i,j])
            else if mine[i,j]='*' then write('.') else write(mine[i,j]);
        if j=kolom then writeln;
      end;
  end;

begin
  clrscr;
  write('Masukkan jumlah baris (0 < baris < 999) : ');
  readln(baris);
  write('Masukkan jumlah kolom (0 < kolom < 999) : ');
  readln(kolom);
  randomize;
  for i:=1 to baris do
    for j:=1 to kolom do
      begin
        temp:=random(2);
        if temp   =1 then input:='.' else input:='*';
        mine[i,j]:=input;
      end;
  v:=0;
  for i:=1 to baris do
    for j:=1 to kolom do
      begin
        bomb:=false;
        mines:=0;
        for k:=i-1 to i+1 do
          for l:=j-1 to j+1 do
            begin
              if mine[i,j]='*' then bomb:=true
                else if not((k=i) and (l=j)) then if mine[k,l]='*' then mines:=mines+1;
            end;
        if bomb=true then hasil[i,j]:='*'
          else
            begin
              str(mines,temp1);
              hasil[i,j]:=temp1;
              v:=v+1;
            end;
      end;
  stat:=true;
  vans:=0;
  while stat=true do
    begin
      stat1:=false;
      temp:=0;
      while stat1=false do
        begin
          if temp=0 then
            begin
              write('Masukkan koordinat (baris [spasi] kolom) : ');
              readln(barisi,kolomi);
            end;
          if (barisi<1) or (barisi>baris) or (kolomi<1) or (kolomi>kolom) then
            begin
              writeln('Input salah. Coba lagi.');
              write('Masukkan koordinat (baris [spasi] kolom) : ');
              readln(barisi,kolomi);
              temp:=1;
            end;
          if not((barisi<1) or (barisi>baris) or (kolomi<1) or (kolomi>kolom)) then
              begin
                stat1:=true;
                writeln;
              end;
        end;
      if hasil[barisi,kolomi]='*' then
        begin
          writemine(baris,kolom,true);
          writeln('Anda Kalah!!');
          readln;
          exit;
        end
      else
        begin
          mine[barisi,kolomi]:=hasil[barisi,kolomi];
          writemine(baris,kolom,false);
          writeln;
          vans:=vans+1;
        end;
      if vans=v then
        begin
          writeln('Selamat!! Anda Menang!!');
          readln;
          exit;
        end;
    end;
end.
