const d:array[0..9] of char = ('0','1','2','3','4','5','6','7','8','9');

function dapatkanwaktu:longint;
  var
    ch:char;
    h,m:longint;
  
  begin
    read(ch); h := ord(ch)-ord('0');
    read(ch); h := 10*h+ord(ch)-ord('0');
    read(ch);
    read(ch); m := ord(ch)-ord('0');
    read(ch); m := 10*m+ord(ch)-ord('0');
    read(ch);
    exit(60*h+m);
  end;

function waktu(x:longint):ansistring;
  begin
    exit(d[(x div 60) div 10]+d[(x div 60) mod 10]+':'+d[(x mod 60) div 10]+d[(x mod 60) mod 10]);
  end;

var
  day,n,i,nap,best,start:longint;
  a,b:array[0..111111] of longint;
  tab:array[0..111111] of longint;

begin
  repeat
    inc(day);
    readln(n);
    a[0] := 599; b[0] := 600;
    for i:=1 to n do
      begin
        a[i] := dapatkanwaktu;
        b[i] := dapatkanwaktu;
        readln;
      end;
    a[n+1] := 1080; b[n+1] := 1081;
    fillchar(tab,sizeof(tab),0);
    for i:=0 to n+1 do
      begin
        inc(tab[a[i]]); dec(tab[b[i]]);
      end;
    for i:=600 to 1080 do tab[i] := tab[i-1]+tab[i];
    nap := 0; best := 0; start := 0;
    for i:=600 to 1080 do
      begin
        if tab[i]=0 then begin inc(nap); continue; end;
        if tab[i-1]>0 then continue;
        if nap>best then begin best := nap; start := i-nap; end;
        nap := 0;
      end;
    if best<60 then
      writeln('Day #',day,': the longest nap starts at ',waktu(start),' and will last for ',best,' minutes.')
    else
      writeln('Day #',day,': the longest nap starts at ',waktu(start),' and will last for ',best div 60,' hours and ',best mod 60,' minutes.')
  until eof;
end.
