var
  i,n,m,j,sr,sc:longint;
  a,x:array[-1..5000,-1..5000] of char;
  v:array[-1..5000,-1..5000,0..1] of boolean;

procedure fill(lr,lc,r,c,x:longint);
  begin
    if a[r][c]='#' then exit;
    if v[r][c][x] then exit;
    if (r=0) then begin r:=n; x:=1; end;
    if (c=0) then begin c:=m; x:=1; end;
    if (r=n) then begin r:=1; x:=1; end;
    if (c=m) then begin c:=1; x:=1; end;
    if v[r][c][x] then exit;
    v[r][c][x] := true;
    if (lr<>n)or(lc<>c) then fill(r,c,r-1,c,x);
    if (lr<>1)or(lc<>c) then fill(r,c,r+1,c,x);
    if (lc<>m)or(lr<>r) then fill(r,c,r,c-1,x);
    if (lc<>1)or(lr<>r) then fill(r,c,r,c+1,x);
  end;

begin
  fillchar(a,sizeof(a),'#');
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
          sr := i; sc := j;
        end;
  fill(0,0,sr,sc,0);
  if v[sr][sc][1] then writeln('Yes') else writeln('No');
end.
