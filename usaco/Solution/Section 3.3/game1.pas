{
ID: a_zaky01
PROG: game1
LANG: PASCAL
}

uses
  math;

var
  n,i,len:integer;
  sum,best,num:array[0..100] of integer;
  fin,fout:text;

begin
  assign(fin,'game1.in');
  assign(fout,'game1.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  sum[0]:=0;
  for i:=1 to n do
    begin
      read(fin,num[i]);
      sum[i]:=sum[i-1]+num[i];
    end;
  for i:=1 to n do best[i]:=num[i];
  for len:=2 to n do
    for i:=1 to n+1-len do
      best[i]:=sum[i+len-1]-sum[i-1]-min(best[i],best[i+1]);
  writeln(fout,best[1],' ',sum[n]-best[1]);
  close(fin);
  close(fout);
end.
