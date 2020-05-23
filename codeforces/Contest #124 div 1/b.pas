var
  i,n,m,j,sr,sc:longint;
  a,x:array[-1..5000,-1..5000] of char;
  v:array[-1..5000,-1..5000] of boolean;

procedure fill(r,c:longint);
  begin
    if (r=0) or (c=0) or (r>3*n) or (c>3*m) then exit;
    if x[r][c]='#' then exit;
    if v[r][c] then exit;
    v[r][c] := true;
    fill(r-1,c);
    fill(r+1,c);
    fill(r,c-1);
    fill(r,c+1);
  end;

begin
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do read(a[i][j]);
      readln;
    end;
  for i:=1 to n do
    for j:=1 to m do
      if a[i][j]='S' then
        begin
          a[i][j] := '.';
          sr := i+n; sc := j+m;
        end;
  for i:=1 to 3*n do
    for j:=1 to 3*m do
      x[i][j] := a[((i-1) mod n) + 1][((j-1) mod m) + 1];
  fill(sr,sc);
  if v[sr-n,sc-m]
  or v[sr-n,sc]
  or v[sr-n,sc+m]
  or v[sr,sc-m]
  or v[sr,sc+m]
  or v[sr+n,sc-m]
  or v[sr+n,sc]
  or v[sr+n,sc+m]
  then writeln('Yes') else writeln('No');
end.
