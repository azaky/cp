var
  n,i,j,a,b:integer;
  best,cur:longint;
  p,sum:array[0..100,0..100] of longint;

begin
  readln(n);
  for i:=1 to n do
    for j:=1 to n do
      read(p[i,j]);
  fillchar(sum,sizeof(sum),0);
  for i:=1 to n do
    for j:=1 to n do sum[i,j]:=sum[i,j-1]+p[i,j];
  best:=-1000000000;
  for a:=0 to n-1 do
    for b:=a+1 to n do
      begin
        cur:=0;
        for i:=1 to n do
          begin
            cur:=cur+sum[i,b]-sum[i,a];
            if cur>best then best:=cur;
            if cur<0 then cur:=0;
          end;
      end;
  writeln(best);
end.

