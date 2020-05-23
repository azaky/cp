uses math;

var
  n,m,i,maxscore,minscore:longint;
  a,b:array[0..1000005] of longint;

begin
  readln(n,m);
  for i:=1 to m do read(a[i]);
  for i:=1 to m do read(b[i]);
  //calculating max score
  for i:=1 to m do inc(maxscore,min(a[i],b[i]));
  //calculating min score
  for i:=1 to m do
    if a[i]+b[i]>n then inc(minscore,a[i]+b[i]-n);
  writeln(minscore,'-',maxscore);
end.
