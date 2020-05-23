var
  m,n,i,j,b,k,t,area,ans:integer;
  a,s:array[0..24,0..24] of integer;

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
  s:=a;
  ans:=0;
  for i:=0 to m-1 do
    for j:=0 to n-1 do
      if a[i,j]<>0 then
        begin
          t:=a[i,j];
          area:=0; fill(i,j);
          if area>ans then
            begin
              ans:=area;
              b:=i; k:=j;
            end;
        end;
  a:=s; t:=a[b,k]; fill(b,k);
  for i:=m-1 downto 0 do
    for j:=0 to n-1 do
      if a[i,j]=0 then
        begin
          for k:=i-1 downto -1 do
            if k<0 then break
              else if a[k,j]<>0 then break;
          if k<0 then continue;
          a[i,j]:=a[k,j]; a[k,j]:=0;
        end;
  for i:=0 to m-1 do
    for j:=0 to n-1 do
      if a[i,j]=0 then
        if j+1=n then writeln('.')
          else write('. ')
        else if j+1=n then writeln(a[i,j])
          else write(a[i,j],' ');
end.

