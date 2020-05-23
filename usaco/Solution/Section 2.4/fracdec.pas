{
ID: a_zaky01
PROG: fracdec
LANG: PASCAL
}

var
  n,d,len,k,sisa,temp,c2,c5,c,i:longint;
  fin,fout:text;

function gcd(a,b:longint):longint;
  begin
    if b=0 then gcd:=a
      else if a<b then gcd:=gcd(b,a)
        else gcd:=gcd(b,a mod b);
  end;

begin
  assign(fin,'fracdec.in');
  assign(fout,'fracdec.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n,d);
  write(fout,trunc(n/d),'.');
  if trunc(n/d)=0 then len:=2
    else len:=trunc(ln(n/d)/ln(10))+2;
  n:=n mod d;
  if n=0 then write(fout,0)
    else
      begin
        k:=gcd(n,d);
        n:=n div k;
        d:=d div k;
        temp:=d;
        c2:=0;
        c5:=0;
        while temp mod 2=0 do
          begin
            inc(c2);
            temp:=temp div 2;
          end;
        while temp mod 5=0 do
          begin
            inc(c5);
            temp:=temp div 5;
          end;
        if c2>c5 then c:=c2
          else c:=c5;
        for i:=1 to c do
          begin
            inc(len);
            write(fout,trunc(10*n/d));
            n:=(n*10) mod d;
          end;
        if n<>0 then
          begin
            write(fout,'(');
            inc(len);
            sisa:=n;
            repeat
              inc(len);
              if len mod 76=0 then writeln(fout,trunc(10*n/d))
                else write(fout,trunc(10*n/d));
              n:=(n*10) mod d;
            until sisa=n;
            inc(len);
            if len mod 76=0 then writeln(fout,')')
              else write(fout,')');
          end;
      end;
  if len mod 76<>0 then writeln(fout);
  close(fin);
  close(fout);
end.
