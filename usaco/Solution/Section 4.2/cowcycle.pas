{
ID: a_zaky01
PROG: cowcycle
LANG: PASCAL
}

var
  f,r,f1,r1,f2,r2,i:integer;
  count:longint;
  bestvar:extended;
  gf,ansf:array[0..5] of integer;
  gr,ansr:array[0..10] of integer;
  ratio:array[1..50] of extended;
  fin,fout:text;

procedure sort(l,r:integer);
  var
    i,j:integer;
    mid,temp:extended;

  begin
    i:=l;
    j:=r;
    mid:=ratio[(l+r) div 2];
    repeat
      while ratio[i]<mid do inc(i);
      while ratio[j]>mid do dec(j);
      if i<=j then
        begin
          temp:=ratio[i];
          ratio[i]:=ratio[j];
          ratio[j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

procedure findr(k:integer);
  var
    i,j,n:integer;
    mean,variance:extended;

  begin
    if (k>1) and (gf[f]*r2<3*gf[1]*gr[1]) then exit;
    if k>r then
      if gf[f]*gr[r]>=3*gf[1]*gr[1] then
        begin
          inc(count);
          for i:=1 to f do
            for j:=1 to r do
              ratio[r*(i-1)+j]:=gf[i]/gr[r+1-j];
          n:=f*r-1;
          sort(1,n+1);
          mean:=(ratio[f*r]-ratio[1])/n;
          variance:=0.0;
          for i:=1 to n do variance:=variance+sqr(ratio[i+1]-ratio[i]);
          variance:=(variance/n)-sqr(mean);
          if variance<bestvar then
            begin
              bestvar:=variance;
              ansf:=gf;
              ansr:=gr;
            end;
        end
      else exit
    else for i:=gr[k-1]+1 to r2-(r-k) do
      begin
        gr[k]:=i;
        findr(k+1);
      end;
  end;

procedure findf(k:integer);
  var
    i:integer;

  begin
    if k>f then
      if gf[f]*r2>=3*gf[1]*r1 then findr(1)
        else exit
      else for i:=gf[k-1]+1 to f2-(f-k) do
        begin
          gf[k]:=i;
          findf(k+1);
        end;
  end;

begin
  assign(fin,'cowcycle.in');
  assign(fout,'cowcycle.out');
  reset(fin);
  rewrite(fout);
  readln(fin,f,r);
  readln(fin,f1,f2,r1,r2);
  gf[0]:=f1-1;
  gr[0]:=r1-1;
  bestvar:=1000000000.0;
  gf[1]:=f1;
  findf(2);
  if f1<>f2 then
    begin
      gf[1]:=f1+1;
      findf(2);
    end;
  for i:=1 to f-1 do write(fout,ansf[i],' ');
  writeln(fout,ansf[f]);
  for i:=1 to r-1 do write(fout,ansr[i],' ');
  writeln(fout,ansr[r]);
  close(fin);
  close(fout);
end.
