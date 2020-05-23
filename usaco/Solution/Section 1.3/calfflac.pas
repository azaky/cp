{
ID: a_zaky01
PROG: calfflac
LANG: PASCAL
}

const
  abjad='abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';

var
  i,j,len,max,p,l,r,templ,tempp,mid,count:longint;
  input:char;
  a:array[0..20001] of char;
  fin,fout:text;

label
  start;

label
  finish;

begin
  assign(fin,'calfflac.in');
  assign(fout,'calfflac.out');
  reset(fin);
  rewrite(fout);
  j:=0;
  while not(eof(fin)) do
    begin
      read(fin,input);
      if pos(input,abjad)<>0 then
        begin
          inc(j);
          a[j]:=upcase(input);
        end;
    end;
  close(fin);
  len:=j; {length of text}
  max:=0; {maximum length of palindromes}
  p:=0; {the least position of the longest palindromes}
  for i:=1 to len do
    begin
      {consider the palindrome with odd number of length}
      l:=i;
      r:=i;
      start:
      while ((l>0) and (r<len+1)) and (a[l]=a[r]) do
        begin
          dec(l);
          inc(r);
        end;
      inc(l);
      dec(r);
      if (r-l+1)>max then
        begin
          max:=r-l+1;
          p:=l;
        end;
      if (r-l+1) mod 2=0 then goto finish;
      {consider the palindrome with even number of length}
      if a[i]=a[i+1] then
        begin
          l:=i;
          r:=i+1;
          goto start;
        end;
      finish:
    end;
  writeln(fout,max);
  count:=0;
  assign(fin,'calfflac.in');
  reset(fin);
  while count<p do
    begin
      read(fin,input);
      if pos(input,abjad)<>0 then inc(count);
    end;
  count:=1;
  write(fout,input);
  while count<max do
    begin
      read(fin,input);
      if pos(input,abjad)<>0 then inc(count);
      write(fout,input);
    end;
  writeln(fout);
  close(fin);
  close(fout);
end.
