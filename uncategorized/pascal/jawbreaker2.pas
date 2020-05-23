var
  m,n,i,j,b,k,t,area,ans:integer;
  a:array[0..24,0..24] of integer;

procedure fill(b,k:integer);
  begin
    if (b<0) or (k<0) or (b>=m) or (k>=n) then exit;
    if a[b,k]<>t then exit;
    inc(area); a[b,k]:=0;
    fill(b+1,k);
    fill(b,k+1);
    fill(b-1,k);
    fill(b,k-1);
  end;

begin
  readln(m,n);
  for i:=0 to m-1 do
    for j:=0 to n-1 do read(a[i,j]);
  ans:=0;
  for i:=0 to m-1 do
    for j:=0 to n-1 do
      if a[i,j]<>0 then
        begin
          t:=a[i,j];
          area:=0; fill(i,j);
          if area>ans then ans:=area;
        end;
  writeln(ans*(ans-1));
end.

