uses
  crt;

var
  baris,diff,bomba,count,kolom,i,j,k,l,mines,temp,barisi,kolomi,v,vans,z,area:longint;
  input,temp1:string;
  bomb:boolean;
  mine,hasil:array[0..1000,0..1000] of string;
  re,check:array[0..1000,0..1000] of boolean;

procedure writemine(var baris,kolom:longint; stat2:boolean);

  procedure zero(baris,kolom:longint);
    var
      i,j,k,l:longint;

    begin
      for i:=1 to baris do
        for j:=1 to kolom do
          if (mine[i,j]='0') and (not(re[i,j])) then
            begin
              if check[i,j] then vans:=vans+1;
              check[i,j]:=false;
              re[i,j]:=true;
              for k:=(i-1) to (i+1) do
                for l:=(j-1) to (j+1) do
                  if (i<>k) or (j<>l) then
                    begin
                      mine[k,l]:=hasil[k,l];
                      if check[k,l] then vans:=vans+1;
                      check[k,l]:=false;
                      if (hasil[k,l]='0') and not(re[k,l]) then zero(baris,kolom);
                    end;
            end;
    end;

  var
    i,j:integer;

  begin
    clrscr;
    zero(baris,kolom);
    write('   ');
    for i:=1 to kolom do write(i:3);
    writeln;
    writeln;
    for i:= 1 to baris do
      begin
        writeln;
        write(i:3);
        write(' ');
        for j:=1 to kolom do
          if stat2=true then write(' ',mine[i,j],' ')
            else if mine[i,j]='*' then write(' . ')
              else write(' ',mine[i,j],' ');
        if j=kolom then writeln;
      end;
    writeln;
  end;

begin
  clrscr;
  write('Masukkan jumlah baris (1 <= baris <= 20) : ');
  readln(baris);
  while (baris<1) or (baris>20) do
    begin
      writeln('Input salah. Coba lagi.');
      write('Masukkan jumlah baris (1 <= baris <= 20) : ');
      readln(baris);
    end;
  write('Masukkan jumlah kolom (0 <= kolom <= 20) : ');
  readln(kolom);
  while (kolom<1) or (kolom>20) do
    begin
      writeln('Input salah. Coba lagi.');
      write('Masukkan jumlah kolom (1 <= baris <= 20) : ');
      readln(kolom);
    end;
  write('Pilih tingkat kesulitan (easy, medium, hard, insane) : ');
  readln(input);
  while (input<>'easy') and (input<>'medium') and (input<>'hard') and (input<>'insane') do
    begin
      writeln('Input salah. Coba lagi.');
      write('Pilih tingkat kesulitan (easy, medium, hard) : ');
      readln(input);
    end;
  if input='easy' then diff:=10
    else if input='medium' then diff:=8
      else if input='hard' then diff:=5
        else if input='insane' then diff:=1;
  bomba:=0;
  count:=0;
  randomize;
  for i:=1 to baris do
    for j:=1 to kolom do
      begin
        inc(count);
        temp:=random(2);
        if bomba>(count div diff) then input:='.'
          else if temp   =1 then input:='.' else
            begin
              input:='*';
              inc(bomba);
            end;
        mine[i,j]:=input;
      end;
  v:=0;
  for i:=0 to (baris+1) do
    for j:=0 to (kolom+1) do
      begin
        re[i,j]:=false;
        check[i,j]:=false;
      end;
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
              check[i,j]:=true;
              hasil[i,j]:=temp1;
              v:=v+1;
            end;
      end;
  vans:=0;
  while true do
    begin
      write('Tebak atau tandai? : ');
      readln(input);
      while (input<>'tebak') and (input<>'tandai') do
        begin
          writeln('Input salah. Coba lagi.');
          write('Tebak atau tandai : ');
          readln(input);
        end;
      write('Masukkan koordinat (baris [spasi] kolom) : ');
      readln(barisi,kolomi);
      while (barisi<1) or (barisi>baris) or (kolomi<1) or (kolomi>kolom) do
        begin
          writeln('Input salah. Coba lagi.');
          write('Masukkan koordinat (baris [spasi] kolom) : ');
          readln(barisi,kolomi);
        end;
      if input='tandai' then
        begin
          mine[barisi,kolomi]:='Ú';
          writemine(baris,kolom,false);
          writeln;
        end
      else if hasil[barisi,kolomi]='*' then
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
          if check[barisi,kolomi] then vans:=vans+1;
          check[barisi,kolomi]:=false;
        end;
      if vans=v then
        begin
          writeln('Selamat!! Anda Menang!!');
          readln;
          exit;
        end;
    end;
end.
