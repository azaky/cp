{
ID: a_zaky01
PROG: hamming
LANG: PASCAL
}

var
  n,b,d,i,k,m:integer;
  stat:boolean;
  a:array[1..64] of integer;
  fin,fout:text;

function hamming(c,d:integer):integer;
  var
    k:integer;

  begin
    hamming:=0;
    k:=0;
    while k<b do
      begin
        if (c-d) mod 2<>0 then inc(hamming);
        c:=c div 2;
        d:=d div 2;
        inc(k);
      end;
  end;

begin
  assign(fin,'hamming.in');
  assign(fout,'hamming.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n,b,d);
  m:=0;
  k:=1;
  a[k]:=m;
  while k<n do
    begin
      inc(m);
      stat:=true;
      for i:=1 to k do
        if hamming(a[i],m)<d then
          begin
            stat:=false;
            break;
          end;
      if stat then
        begin
          inc(k);
          a[k]:=m;
        end;
    end;
  for i:=1 to n do
    if (i=n) or (i mod 10=0) then writeln(fout,a[i])
      else write(fout,a[i],' ');
  close(fin);
  close(fout);
end.
