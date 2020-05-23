{
ID: a_zaky01
PROG: treasure
LANG: PASCAL
}

uses
  math;
 
var
  n,i,len:longint;
  c,sum,best:array[0..5000] of longint;
  
begin
  assign(input,'treasure.in');
  assign(output,'treasure.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do readln(c[i]);
  for i:=1 to n do sum[i]:=sum[i-1]+c[i];
  for len:=1 to n do
    for i:=0 to n-len do
      best[i]:=sum[i+len]-sum[i]-min(best[i],best[i+1]);
  writeln(best[0]);
  close(input);
  close(output);
end.
 