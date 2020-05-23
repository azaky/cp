uses
  crt;

var
  r,c,i,j,exitr,exitc,r1,c1,tempr,tempc,step:longint;
  win,ok:boolean;
  dir,ask:char;
  input:string;
  a:array[1..50,1..50] of char;

label
  start,lose;

procedure delay(t:real);
  var
    i,k,s,b:longint;

  begin
    k:=round(100000000*t);
    for i:=1 to k do s:=b;
  end;

procedure startgame;
  begin
    writeln('------------------------------------untitled-----------------------------------');
    writeln('-----------------------------------version 1.0---------------------------------');
    writeln;
    writeln('Play : Start the Game');
    writeln('Help : Instruction');
    writeln('HiSc : High Score');
    writeln('Exit : Exit the Game');
  end;

procedure writefield;
  var
    i,j:longint;

  begin
    clrscr;
    write('  ');
    for i:=1 to c do write(i:3);
    writeln;
    writeln;
    for i:=1 to r do
      begin
        write(i:2);
        for j:=1 to c do
          if (a[j,i]='.') and ((i=exitr) and (j=exitc)) then write('  E')
            else write('  ',a[j,i]);
        writeln;
        writeln;
      end;
    writeln;
    writeln('Number of Step(s) = ',step);
    writeln;
  end;

procedure readdata(level:string);
  var
    fname:string;
    i,j:longint;
    f:text;

  begin
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
            if a[j,i]='E' then
              begin
                a[j,i]:='.';
                exitr:=i;
                exitc:=j;
              end;
          end;
      end;
    close(f);
  end;

begin
  start:
  clrscr;
  startgame;
  repeat
    readln(input);
    for i:=1 to length(input) do input[i]:=upcase(input[i]);
    ok:=(input='PLAY') or (input='HELP') or (input='HISC') or (input='EXIT');
    if not ok then writeln('Invalid Input. Please Try Again.');
  until ok;
  write('Input the Level Number : ');
  readln(input);
  readdata(input);
  win:=false;
  step:=0;
  writefield;
  while not win do
    begin
      write('Input the Task (coloumn [space] row [space] direction) : ');
      read(c1,r1);
      read(dir);
      readln(dir);
      inc(step);
      //while (dir<>'D') and (dir<>'U') and (dir<>'R') and (dir<>'L') do read(dir);
      if (a[c1,r1]='D') or (a[c1,r1]='M') then
        while true do
          begin
            writefield;
            delay(0.50);
            tempr:=r1;
            tempc:=c1;
            case dir of
                'U':dec(r1);
                'D':inc(r1);
                'R':inc(c1);
                'L':dec(c1);
              end;
            if (r1<1) or (r1>r) or (c1<1) or (c1>c) then goto lose
              else if (a[c1,r1]='.') then
                begin
                  a[c1,r1]:=a[tempc,tempr];
                  a[tempc,tempr]:='.';
                end
              else if (a[c1,r1]='D') or (a[c1,r1]='M') then break
          end
        else
          begin
            dec(step);
            writefield;
          end;
      r1:=tempr;
      c1:=tempc;
      if (a[c1,r1]='M') and (exitr=r1) and (exitc=c1) then win:=true;
    end;
  if win then writeln('Congratulation!! You Won!!');
  lose:
  if not win then
    begin
      a[tempc,tempr]:='.';
      writefield;
      writeln('You Lose!!');
    end;
  writeln;
  repeat
    write('Try Again? (Y/N) : ');
    readln(ask);
    upcase(ask);
    ok:=ask in ['Y','N'];
    if not ok then writeln('Invalid Input. Please Try Again');
  until ok;
  if ask='Y' then goto start;
end.
