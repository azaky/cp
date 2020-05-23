var
  n,m,i,j,ans,temp,area,posi,posj:longint;
  a:array[0..51,0..51] of char;
  deg:array[0..51,0..51] of longint;
  visit:array[0..51,0..51] of boolean;

procedure fill(i,j:longint);
  begin
    if visit[i][j] then exit;
    if (i=0) or (j=0) or (i>n) or (j>m) then exit;
    if a[i][j]<>'#' then exit;
    inc(temp); visit[i][j]:=true;
    fill(i,j-1);
    fill(i,j+1);
    fill(i-1,j);
    fill(i+1,j);
  end;

begin
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do read(a[i][j]);
      readln;
    end;
  ans := maxlongint;
  for i:=1 to n do
    for j:=1 to m do
      begin
        if a[i][j]='#' then inc(area);
        deg[i][j] := 0;
        if a[i][j-1]='#' then inc(deg[i][j]);
        if a[i][j+1]='#' then inc(deg[i][j]);
        if a[i-1][j]='#' then inc(deg[i][j]);
        if a[i+1][j]='#' then inc(deg[i][j]);
        if a[i][j]='#' then
          if deg[i][j]<ans then ans := deg[i][j];
      end;
  if area - ans < 2 then writeln(-1) else writeln(ans);
  halt;
  while true do
    begin
      inc(ans); dec(area);
      if area = 1 then break;
      posi:=0; posj:=0;
      for i:=1 to n do
        for j:=1 to m do
          if (deg[i][j]>deg[posi][posj]) and (a[i][j]='#') then begin posi := i; posj := j; end;
      //remove posi posj
      a[posi][posj] := '.';
      dec(deg[posi][posj-1]);
      dec(deg[posi][posj+1]);
      dec(deg[posi-1][posj]);
      dec(deg[posi+1][posj]);
      //floodfill
      fillchar(visit,sizeof(visit),false);
      temp := 0;
      for i:=1 to n do
        if temp = 0 then
          for j:=1 to m do
            if a[i][j]='#' then begin fill(i,j); break; end;
      if temp<area then break;
    end;
  if area<2 then writeln(-1) else writeln(ans);
end.
//apasih kok compile error
