uses
  crt;

const
  maxlevel=10;

var
  i,c,r,exitc,exitr,step,level:longint;
  ask:char;
  win:boolean;
  input:string;
  a:array[1..50,1..50] of char;

label
  start,play;

procedure delay(t:real);
  var
    i,k,s,b:longint;

  begin
    k:=round(100000000*t);
    for i:=1 to k do s:=b;
  end;

procedure mainmenu;
  begin
    clrscr;
    writeln('------------------------------------untitled-----------------------------------');
    writeln('-----------------------------------version 1.0---------------------------------');
    writeln;
    writeln('Play : Start the Game');
    writeln('Solv : See the Solution');
    writeln('Help : Instruction');
    writeln('Exit : Exit the Game');
    writeln;
  end;

procedure help;
  begin
    clrscr;
    writeln('                                  Instructions                                 ');
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
    writeln('Press Enter to back to Main Menu.');
    readln;
  end;


procedure writefield;
  var
    i,j:longint;

  begin
    clrscr;
    write('------------------------------------LEVEL ',level,'-----------------------------------');
    if level<10 then writeln('-')
      else writeln;
    writeln;
    write('  ');
    for i:=1 to c do write(i:3);
    writeln;
    writeln;
    for i:=1 to r do
      begin
        write(i:2);
        for j:=1 to c do
          if (a[j,i]='.') and ((i=exitr) and (j=exitc)) then write('  *')
            else write('  ',a[j,i]);
        writeln;
        writeln;
      end;
    writeln;
    if step<=1 then writeln('Number of Step = ',step)
      else writeln('Number of Steps = ',step);
    writeln;
  end;

procedure getlevel(var level:longint);
  var
    fname,input:string;
    i,j:longint;
    ok:boolean;
    f:text;

  begin
    if level=0 then
      begin
        clrscr;
        repeat
          write('Input the Level Number : ');
          readln(level);
          ok:=(level>=1) and (level<=maxlevel);
          if not ok then writeln('The level number is from 1 to ',maxlevel,'. Please try again.');
        until ok;
      end;
    str(level,input);
    fname:='level'+input+'.lvl';
    assign(f,fname);
    reset(f);
    readln(f,c,r);
    for i:=1 to r do
      begin
        readln(f,input);
        for j:=1 to c do
          begin
            a[j,i]:=input[j];
            if a[j,i]='*' then
              begin
                a[j,i]:='.';
                exitr:=i;
                exitc:=j;
              end;
          end;
      end;
    writeln;
    write('Loading');
    delay(2.00);
    write('.');
    delay(2.00);
    write('.');
    delay(2.00);
    write('.');
    delay(2.00);
    close(f);
  end;

function walk(var c1,r1:integer; dir:char):boolean;
  var
    tempr,tempc:integer;
    stop:boolean;

  begin
    walk:=false;
    stop:=false;
    repeat
      writefield;
      delay(1.50);
      tempr:=r1;
      tempc:=c1;
      case dir of
          'U':dec(r1);
          'D':inc(r1);
          'R':inc(c1);
          'L':dec(c1);
        end;
      if (r1<1) or (r1>r) or (c1<1) or (c1>c) then
        begin
          stop:=true;
          walk:=true;
        end
      else if (a[c1,r1]='D') or (a[c1,r1]='M') then stop:=true
        else if (a[c1,r1]='.') then
          begin
            a[c1,r1]:=a[tempc,tempr];
            a[tempc,tempr]:='.';
          end;
    until stop;
    if walk then a[tempc,tempr]:='.';
  end;

procedure startgame;
  var
    c1,r1:integer;
    dir:char;
    inrange,empty,correctdir,stop,fall:boolean;

  begin
    win:=false;
    fall:=false;
    step:=0;
    writefield;
    while not win and not fall do
      begin
        repeat
          inrange:=true;
          empty:=false;
          correctdir:=true;
          write('Input the Task (coloumn [space] row [space] direction) : ');
          read(c1,r1);
          repeat
            read(dir);
            dir:=upcase(dir);
          until (ord(dir)>=65) and (ord(dir)<=90);
          readln;
          inrange:=((c1>=1) and (c1<=c)) and ((r1>=1) and (r1<=r));
          if not inrange then writeln('The coordinate is outside the arena. Please try again.')
            else
              begin
                empty:=a[c1,r1] in ['*','.'];
                if empty then writeln('The coordinate is empty. Please try again.')
                  else
                    begin
                      correctdir:=dir in ['U','D','L','R'];
                      if not correctdir then writeln('Incorrect direction. Please try again.');
                    end;
              end;
        until inrange and not empty and correctdir;
        inc(step);
        fall:=walk(c1,r1,dir);
        case dir of
            'U':inc(r1);
            'D':dec(r1);
            'L':inc(c1);
            'R':dec(c1);
          end;
        if (a[c1,r1]='M') and (exitr=r1) and (exitc=c1) then win:=true;
      end;
    if win then writeln('Congratulation!! You Won!!')
      else if fall then
        begin
          writefield;
          writeln('You Lose!!');
        end;
    writeln;
  end;

procedure solve;
  var
    c1,r1,i,j:integer;
    dir:char;
    temp,ok:boolean;
    fname,input:string;
    f:text;

  begin
    clrscr;
    repeat
      write('Input the Level Number : ');
      readln(level);
      ok:=(level>=1) and (level<=maxlevel);
      if not ok then writeln('The level number is from 1 to ',maxlevel,'. Please try again.');
    until ok;
    str(level,input);
    fname:='level'+input+'.lvl';
    assign(f,fname);
    reset(f);
    readln(f,c,r);
    for i:=1 to r do
      begin
        readln(f,input);
        for j:=1 to c do
          begin
            a[j,i]:=input[j];
            if a[j,i]='*' then
              begin
                a[j,i]:='.';
                exitr:=i;
                exitc:=j;
              end;
          end;
      end;
    writeln;
    write('Loading');
    delay(2.00);
    write('.');
    delay(2.00);
    write('.');
    delay(2.00);
    write('.');
    delay(2.00);
    step:=0;
    while not eof(f) do
      begin
        read(f,c1,r1);
        read(f,dir);
        readln(f,dir);
        delay(2.00);
        inc(step);
        temp:=walk(c1,r1,dir);
      end;
    close(f);
    writeln('Press Enter to back to main menu.');
    readln;
  end;

begin
  start:
  mainmenu;
  repeat
    readln(input);
    for i:=1 to length(input) do input[i]:=upcase(input[i]);
    if not ((input='PLAY') or (input='SOLV') or (input='HELP') or (input='EXIT')) then writeln('Invalid input. Please try again.');
  until ((input='PLAY') or (input='SOLV') or (input='HELP') or (input='EXIT'));
  case input[4] of
    'Y': begin
           level:=0;
           play:
           getlevel(level);
           startgame;
           if win then
             if level=maxlevel then
               begin
                 writeln('You has finished the game!!');
                 writeln('Press Enter to back to main menu.');
                 readln;
                 goto start;
               end
             else
               begin
                 inc(level);
                 repeat
                   write('Go to the next level? (Y/N) : ');
                   readln(ask);
                   ask:=upcase(ask);
                   if not (ask in ['Y','N']) then writeln('Invalid Input. Please Try Again');
                 until (ask in ['Y','N']);
                 if ask='Y' then goto play
                   else goto start;
               end
           else
             begin
               repeat
                 write('Try Again? (Y/N) : ');
                 readln(ask);
                 ask:=upcase(ask);
                 if not (ask in ['Y','N']) then writeln('Invalid Input. Please Try Again');
               until (ask in ['Y','N']);
               if ask='Y' then goto play
                 else goto start;
             end;
         end;
    'V': begin
           solve;
           goto start;
         end;
    'P': begin
           //help;
           goto start;
         end;
    'T': exit;
  end;
end.
