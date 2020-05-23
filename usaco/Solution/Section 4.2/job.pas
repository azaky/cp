{
ID: a_zaky01
PROG: job
LANG: PASCAL
}

uses
  math;

const
  maxtime=6217835;

var
  n,i,j,ma,mb,ansa,ansb,best:longint;
  ta,da,tb,db:array[0..30] of longint;
  donea,doneb:array[1..1000] of longint;
  fin,fout:text;


begin
  assign(fin,'job.in');
  assign(fout,'job.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n,ma,mb);
  for i:=1 to ma do read(fin,ta[i]);
  for i:=1 to mb do read(fin,tb[i]);
  ta[0]:=maxtime;
  tb[0]:=maxtime;
  for i:=1 to n do
    begin
      best:=0;
      for j:=1 to ma do
        if ta[j]+da[j]<ta[best]+da[best] then best:=j;
      donea[i]:=ta[best]+da[best];
      inc(da[best],ta[best]);
    end;
  ansa:=donea[n];
  ansb:=0;
  for i:=1 to n do
    begin
      best:=0;
      for j:=1 to mb do
        if tb[j]+db[j]<tb[best]+db[best] then best:=j;
      doneb[i]:=tb[best]+db[best];
      inc(db[best],tb[best]);
      ansb:=max(ansb,donea[n+1-i]+doneb[i]);
    end;
  writeln(fout,ansa,' ',ansb);
  close(fin);
  close(fout);
end.
