{
ID: a_zaky01
PROG: agrinet
LANG: PASCAL
}

var
  n,i,j,count,total,min,x:longint;
  a:array[1..100,1..100] of longint;
  best:array[1..100] of longint;
  intree:array[1..100] of boolean;
  fin,fout:text;
 
begin
  assign(fin,'agrinet.in');
  assign(fout,'agrinet.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do
    for j:=1 to n do read(fin,a[i,j]);
  count:=0;
  total:=0;
  intree[1]:=true;
  for i:=2 to n do best[i]:=a[i,1];
  while count<n-1 do
    begin
      min:=100001;
      for i:=1 to n do
        if not intree[i] then
          if best[i]<min then
            begin
              x:=i;
              min:=best[i];
            end;
      total:=total+min;
      intree[x]:=true;
      for i:=1 to n do
        if not intree[i] then
          if best[i]>a[i,x] then best[i]:=a[i,x];
      inc(count);
    end;
  writeln(fout,total);
  close(fin);
  close(fout);
end.
