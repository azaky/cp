var
  ans,i,a,b,c,m,n:longint;
  x:array[0..1000] of longint;

begin
{
  for a:=1 to 8 do
    for b:=1 to 8 do
      for c:=1 to 8 do
        if (a+b+c=8) and (a<>b) and (b<>c) and (c<>a) then inc(ans);
  writeln(ans); halt;
  for m:=1 to 1000 do
    for n:=1 to 1000 do
      if (m mod 2=0) and (n mod 2=0) and (abs(1/m+4/n-1/12)<1e-9) then
        begin
          writeln('(',m,', ',n,')');
        end;
  halt;
  x[1]:=2;
  for i:=2 to 125 do x[i]:=x[i-1]+1;
  for i:=1 to 125 do inc(ans,x[i]);
  writeln(ans); halt;
  for a:=1 to 9 do
    for b:=a to 9 do
      for c:=b+1 to 9 do inc(ans);
  writeln(ans); halt;
}
  ans:=0;
  for i:=1501 to 2010 do
    if ((i mod 2=0) and (i mod 3=0)) and ((i mod 5<>0) or (i mod 7<>0)) then inc(ans);
  writeln(ans);
  ans:=0;
  for i:=1501 to 2010 do
    if ((i mod 2=0) and (i mod 3=0)) and ((i mod 5<>0) and (i mod 7<>0)) then inc(ans);
  writeln(ans);
end.
