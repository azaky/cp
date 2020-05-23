uses math;

var
  n,m,a,b,i,j,ans:longint;
  marker,cap:array[0..1111,0..1111] of longint;
  mm,cc:array[0..1111] of longint;
  
begin
  readln(n,m);
  for i:=1 to n do
    begin
      readln(a,b);
      inc(marker[a,b]); inc(mm[b]);
    end;
  for i:=1 to m do
    begin
      readln(a,b);
      inc(cap[a,b]); inc(cc[b]);
    end;
  //first answer
  ans:=0;
  for i:=1 to 1000 do ans:=ans+min(mm[i],cc[i]);
  write(ans);
  //second answer
  ans:=0;
  for i:=1 to 1000 do
    for j:=1 to 1000 do
      ans:=ans+min(marker[i,j],cap[i,j]);
  writeln(' ',ans);
end.
