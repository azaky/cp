uses
  crt;

var
  n:longint;
  a:array[1..1000] of real;

procedure qsort;

  procedure sort(l,r: longint);
    var
      i,j:longint;
      x,y:real;

    begin
      i:=l;
      j:=r;
      x:=a[(l+r) div 2];
      repeat
        while a[i]<x do
          inc(i);
        while x<a[j] do
          dec(j);
        if not(i>j) then
          begin
            y:=a[i];
            a[i]:=a[j];
            a[j]:=y;
            inc(i);
            j:=j-1;
          end;
      until i>j;
      if l<j then sort(l,j);
      if i<r then sort(i,r);
    end;

  begin
    sort(1,n);
  end;

procedure frequency;
  var
    count,i:longint;
    x:array[1..1000] of real;
    f:array[1..1000] of longint;

  begin
    count:=1;
    x[1]:=a[1];
    f[1]:=1;
    for i:=2 to n do
      if a[i]=a[i-1] then inc(f[count])
      else
        begin
          inc(count);
          x[count]:=a[i];
          f[count]:=1;
        end;
    for i:=1 to count do writeln(x[i]:1:0,' ',f[i]);
  end;

function mean:real;
  var
    i:longint;
    sum:real;

  begin
    sum:=0;
    for i:=1 to n do sum:=sum+a[i];
    mean:=sum/n;
  end;

function median:real;

  begin
    if n mod 2 =1 then median:=a[(1+n) div 2]
      else median:=(a[n div 2]+a[(n div 2) + 1])/2;
  end;

function modus:real;
  var
    i,j,max,imax:longint;
    q:array[1..1000] of integer;

  begin
    for i:=1 to n do
      begin
        q[i]:=0;
        for j:=1 to n do if a[i]=a[j] then inc(q[i]);
      end;
    max:=0;
    for i:=1 to n do if q[i]>max then
      begin
        imax:=i;
        max:=q[i];
      end;
    modus:=a[imax];
  end;

function quartil(k:integer):real;
  var
    i:real;

  begin
    i:=k*(1+n)/4;
    quartil:=a[trunc(i)]+(a[trunc(i)+1]-a[trunc(i)])*frac(i);
  end;

function desil(k:integer):real;
  var
    i:real;

  begin
    i:=k*(1+n)/10;
    desil:=a[trunc(i)]+(a[trunc(i)+1]-a[trunc(i)])*frac(i);
  end;

function persentil(k:integer):real;
  var
    i:real;

  begin
    i:=k*(1+n)/100;
    persentil:=a[trunc(i)]+(a[trunc(i)+1]-a[trunc(i)])*frac(i);
  end;

function simpangan_rata:real;
  var
    i:longint;
    rata,sum:real;

  begin
    sum:=0;
    rata:=mean;
    for i:=1 to n do
      if rata>a[i] then sum:=sum+rata-a[i]
        else sum:=sum+a[i]-rata;
    simpangan_rata:=sum/n;
  end;

function ragam:real;
  var
    i:longint;
    rata,sum:real;

  begin
    sum:=0;
    rata:=mean;
    for i:=1 to n do sum:=sum+((a[i]-rata)*(a[i]-rata));
    ragam:=sum/n;
  end;

function standard_deviation:real;

  begin
    standard_deviation:=sqrt(ragam);
  end;

//****************************************************************************

procedure input_data;
  var
    i:longint;

  begin
    clrscr;
    for i:=1 to n do a[i]:=0;
    write('Jumlah bilangan (1 <= n <= 100000) : ');
    readln(n);
    writeln('Masukkan data');
    for i:=1 to n do
      begin
        write('data ke-',i,' : ');
        readln(a[i]);
      end;
    qsort;
  end;

procedure statistika;
  var
    input:string;
    temp:longint;

  procedure confirm;
    var
      ans:string;

    begin
      write('Coba lagi? (ya/tidak) : ');
      readln(ans);
      if ans='ya' then statistika else halt;
    end;

  begin
    clrscr;
    writeln('Masukkan input');
    writeln('freq : tabel frekuensi');
    writeln('mean : rata-rata');
    writeln('med  : median');
    writeln('mod  : modus');
    writeln('qi   : kuartil i (1 <= i <= 3)');
    writeln('di   : desil i (1 <= i <= 9)');
    writeln('pi   : persentil i (1 <= i <= 99)');
    writeln('sr   : simpangan rata-rata');
    writeln('rgm  : ragam');
    writeln('sd   : simpangan baku');
    writeln('new  : masukkan data baru');
    writeln('exit : keluar');
    write('Masukkan input : ');
    readln(input);
    if input='freq' then frequency
      else if input='mean' then writeln(mean:1:2)
      else if input='med' then writeln(median:1:2)
      else if input='mod' then writeln(modus:1:2)
      else if input[1]='q' then
        begin
          val(copy(input,2,length(input)),temp);
          writeln(quartil(temp):1:2);
        end
      else if input[1]='d' then
        begin
          val(copy(input,2,length(input)),temp);
          writeln(desil(temp):1:2);
        end
      else if input[1]='p' then
        begin
          val(copy(input,2,length(input)),temp);
          writeln(persentil(temp):1:2);
        end
      else if input='sr' then writeln(simpangan_rata:1:2)
      else if input='rgm' then writeln(ragam:1:2)
      else if input='sd' then writeln(standard_deviation:1:2)
      else if input='new' then
        begin
          input_data;
          statistika;
        end
      else if input='exit' then halt
      else
        begin
          writeln('Input salah. Coba lagi');
          statistika;
        end;
      confirm;
  end;

begin
  input_data;
  statistika;
end.
