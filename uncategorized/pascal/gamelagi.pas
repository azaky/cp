program boxflip;

uses
  crt;

var
  c,r,vans,v,bomb:integer;
  poin:int64;
  input:string;
  stat,cheat:boolean;
  poinc,poinr,bombc,bombr:array[1..5] of integer;
  field:array[1..5,1..5] of integer;
  statfield:array[1..5,1..5] of boolean;
  hs:text;

label
  mulai;

procedure help;
  var
    input:string;

  begin
    clrscr;
    writeln('                               Petunjuk Permainan                              ');
    writeln;
    writeln('Pada kotak 5x5, terdapat 25 kotak yang masing-masing berisi angka 1, 2, 3, atau');
    writeln('bom. Pada awalnya semua kotak dalam keadaan tertutup. Tugas Anda adalah membuka');
    writeln('semua kotak yang berisi angka 2 dan 3. Jika Anda membuka kotak berisi bom, maka');
    writeln('permainan berakhir. Pada awalnya Anda akan diberi tahu jumlah angka dan banyak ');
    writeln('bom pada masing-masing baris dan kolom, dengan ä menyatakan jumlah angka dan x ');
    writeln('menyatakan banyak bom. Poin Anda pada awalnya adalah 1. Jika Anda membuka kotak');
    writeln('berisi angka, maka poin Anda akan dikalikan dengan angka tersebut. Maka, jika  ');
    writeln('semua kotak berisi angka 2 dan 3 telah dibuka, maka poin Anda tidak bisa ber-  ');
    writeln('tambah lagi dan Anda menang. Jika Anda membuka kotak berisi bom, maka poin Anda');
    writeln('akan menjadi 0 dan Anda kalah.                                                 ');
    writeln('Setiap kali Anda akan membuka sebuah kotak, masukkan input kolom <spasi> baris,');
    writeln('yang akan membuka kotak dengan kolom dan baris tersebut. Contoh input adalah   ');
    writeln('''2 3'' (tanpa tanda kutip) akan membuka kotak pada kolom 2 dan baris 3.       ');
    writeln('Jika Anda ingin keluar dari permainan, tekan ctrl+c.                           ');
    writeln;
    writeln('Tekan Enter untuk kembali ke menu utama.');
    readln;
    goto mulai;
  end;

procedure highscore;

  var
    i,j,k,maxl,maxi:integer;
    temp:int64;
    input:string;
    score:array[1..5] of int64;
    name:array[1..5] of string;

  begin
    clrscr;
    assign(hs,'highscore.txt');
    reset(hs);
    writeln('                                   High Score                                  ');
    writeln;
    maxl:=0;
    maxi:=0;
    for i:=1 to 5 do
      begin
        readln(hs,temp);
        readln(hs,name[i]);
        score[i]:=temp;
        temp:=trunc(ln(temp)/ln(10))+1;
        if temp>maxi then maxi:=temp;
        if length(name[i])>maxl then maxl:=length(name[i]);
      end;
    for i:=1 to 5 do
      begin
        k:=maxl+1-length(name[i]);
        write(i,'. ',name[i]);
        for j:=1 to k do write(' ');
        writeln(score[i]:maxi);
      end;
    close(hs);
    writeln;
    writeln('Reset : Menghapus High Score');
    writeln('Main  : Kembali ke Menu Utama');
    write('Masukkan input : ');
    readln(input);
    while (input<>'Reset') and (input<>'Main') do
      begin
        writeln('Input salah. Coba lagi.');
        write('Masukkan input : ');
        readln(input);
      end;
    if input='Reset' then
      begin
        write('Anda yakin? (ya/tidak) : ');
        readln(input);
        while (input<>'ya') and (input<>'tidak') do
          begin
            writeln('Input salah. Coba lagi.');
            write('Anda yakin? (ya/tidak) : ');
            readln(input);
          end;
        if input='ya' then
          begin
            assign(hs,'highscore.txt');
            rewrite(hs);
            for i:=1 to 5 do
              begin
                writeln(hs,'0');
                writeln(hs,'Anonymous');
              end;
            close(hs);
            highscore;
          end
        else highscore;
      end
    else goto mulai;
  end;

function check(input:string):boolean;
  var
    angka:string;

  begin
    check:=false;
    angka:='12345';
    if not(length(input)=3) then
      else if (pos(input[1],angka)<>0) and (pos(input[3],angka)<>0) and (input[2]=' ') then
        check:=true;
  end;

procedure start;
  var
    i,j:integer;
    input:string;

  begin
    vans:=0;
    v:=0;
    poin:=1;
    writeln;
    write('Pilih tingkat kesulitan (easy/medium/hard) : ');
    readln(input);
    while not(input='easy') and not(input='medium') and not(input='hard') and not(input='win') do
      begin
        writeln('Input salah. Coba lagi.');
        write('Pilih tingkat kesulitan (easy/medium/hard) : ');
        readln(input);
      end;
    if input='easy' then bomb:=3
      else if input='medium' then bomb:=6
        else if input='hard' then bomb:=12
          else if input='win' then bomb:=0;
    clrscr;
    write('  ');
    for i:=1 to 5 do write('  ',i,'  ');
    writeln;
    writeln;
    for i:=1 to 5 do
      begin
        write(i,' ');
        for j:=1 to 5 do write('  .  ');
        writeln('ä=?,; x=?');
        writeln;
      end;
    write('   ');
    for i:=1 to 5 do write('ä=?  ');
    writeln;
    write('   ');
    for i:=1 to 5 do write('x=?  ');
    writeln;
    writeln;
    writeln('Poin Anda = 1');
    writeln;
    write('Masukkan input (kolom <spasi> baris) : ');
    readln(input);
    while not(check(input)) do
      begin
        writeln('Input salah. Coba lagi.');
        write('Masukkan input (kolom <spasi> baris) : ');
        readln(input);
      end;
    val(input[1],c);
    val(input[3],r);
  end;

procedure fillfield;
  var
    i,j,tempbomb:integer;

  begin
    randomize;
    tempbomb:=0;
    for i:=1 to 5 do
    for j:=1 to 5 do
      begin
        if (tempbomb>bomb) or ((i=c) and (j=r)) then field[i,j]:=random(3)+1
          else field[i,j]:=random(4);
        if (field[i,j]=2) or (field[i,j]=3) then inc(v);
        if field[i,j]=0 then inc(tempbomb);
      end;
  end;

procedure setup;
  var
    i,j:integer;

  begin
    stat:=true;
    for i:=1 to 5 do
      begin
        poinc[i]:=0;
        poinr[i]:=0;
        bombc[i]:=0;
        bombr[i]:=0;
      end;
    for i:=1 to 5 do
      for j:=1 to 5 do
        begin
          statfield[i,j]:=true;
          if field[i,j]=0 then inc(bombc[i]) else poinc[i]:=poinc[i]+field[i,j];
          if field[j,i]=0 then inc(bombr[i]) else poinr[i]:=poinr[i]+field[j,i];
        end;
  end;

procedure incpoin;
  begin
    if ((field[c,r]=2) or (field[c,r]=3)) and statfield[c,r] then
      begin
        poin:=poin*field[c,r];
        inc(vans);
      end;
    statfield[c,r]:=false;
  end;

procedure writefield(stat:boolean);
  var
    i,j:integer;

  begin
    clrscr;
    write('  ');
    for i:=1 to 5 do write('  ',i,'  ');
    writeln;
    writeln;
    for i:=1 to 5 do
      begin
        write(i,' ');
        for j:=1 to 5 do
          if (not(stat) and (field[j,i]=0)) and not(cheat) then write('  x  ')
            else if statfield[j,i] then write('  .  ')
              else if field[j,i]=0 then write('  x  ')
                else write('  ',field[j,i],'  ');
        writeln('ä=',poinr[i],'; x=',bombr[i]);
        writeln;
      end;
    write('   ');
    for i:=1 to 5 do write('ä=',poinc[i]:2,' ');
    writeln;
    write('   ');
    for i:=1 to 5 do write('x=',bombc[i]:2,' ');
    writeln;
    writeln;
    if stat or cheat then writeln('Poin Anda = ',poin) else writeln('Poin Anda = 0');
    writeln;
  end;

procedure play;
  var
    input:string;

  procedure halloffame;
    var
      i,j:integer;
      s:int64;
      score:array[1..5] of int64;
      name:array[1..5] of string;

    begin
      assign(hs,'highscore.txt');
      reset(hs);
      for i:=1 to 5 do
        begin
          readln(hs,s);
          score[i]:=s;
          readln(hs,name[i]);
        end;
      if cheat then writeln('Cheater detected. Nilai Anda tidak masuk ke High Score.')
        else if poin<=score[5] then writeln('Maaf. Nilai Anda tidak cukup untuk masuk ke High Score.');
      if not(cheat) then
        for i:=1 to 5 do if poin>score[i] then
          begin
            for j:=5 downto (i+1) do
              begin
                score[j]:=score[j-1];
                name[j]:=name[j-1];
              end;
            score[i]:=poin;
            writeln('Selamat!! Nilai Anda masuk ke High Score!!');
            write('Masukkan nama Anda : ');
            readln(input);
            while length(input)>10 do
              begin
                writeln('Input salah. Coba lagi.');
                write('Masukkan nama Anda : ');
                readln(input);
              end;
            name[i]:=input;
            break;
          end;
      rewrite(hs);
      for i:=1 to 5 do
        begin
          writeln(hs,score[i]);
          writeln(hs,name[i]);
        end;
      close(hs);
      writeln;
    end;

  begin
    write('Masukkan input (kolom <spasi> baris) : ');
    readln(input);
    while not(check(input)) do
      begin
        writeln('Input salah. Coba lagi.');
        write('Masukkan input (kolom <spasi> baris) : ');
        readln(input);
      end;
    val(input[1],c);
    val(input[3],r);
    incpoin;
    if field[c,r]=0 then writefield(false) else writefield(true);
    if (field[c,r]=0) and not(cheat) then
      begin
        writeln('Anda kalah!!');
        writeln('Tekan Enter untuk kembali ke menu utama.');
        readln;
        goto mulai;
      end;
    if v=vans then
      begin
        writeln('Selamat!! Anda menang!!');
        halloffame;
        writeln('Tekan Enter untuk kembali ke menu utama.');
        readln;
        goto mulai;
      end;
  end;

procedure game;
  begin
    start;
    fillfield;
    setup;
    incpoin;
    writefield(true);
    while stat do play;
  end;

begin
  cheat:=false;
  mulai:
  clrscr;
  writeln('------------------------------------untitled-----------------------------------');
  writeln('-----------------------------------version 1.0---------------------------------');
  writeln;
  writeln('Play : Mulai permainan');
  writeln('Help : Petunjuk permainan');
  writeln('HiSc : Lihat High Score');
  writeln('Exit : Keluar');
  write('Masukan input : ');
  readln(input);
  while (input<>'Play') and (input<>'Help') and (input<>'HiSc') and (input<>'Exit') and (input<>'invisible') do
    begin
      writeln('Input salah. Coba lagi.');
      write('Masukkan input : ');
      readln(input);
    end;
  if input='Play' then game
    else if input='Help' then help
      else if input='HiSc' then highscore
        else if input='invisible' then
          begin
            cheat:=not(cheat);
            goto mulai;
          end
        else exit;
end.
