var
  n,m,i,j,area,ak,ab:longint;
  t:char;
  obs:array[0..501,0..501] of boolean;
  a:array[1..500,1..500] of char;

procedure flood(i,j:longint);
  begin
    if (a[i,j]<>t) and (a[i,j] in ['K','B']) then
      begin
        writeln('SERI');
        halt;
      end;
    if obs[i,j] then exit;
    inc(area); obs[i,j]:=true;
    flood(i+1,j);
    flood(i-1,j);
    flood(i,j+1);
    flood(i,j-1);
  end;

begin
  fillchar(obs,sizeof(obs),true);
  readln(m,n);
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(a[i,j]);
          obs[i,j]:=a[i,j]='#';
        end;
      readln;
    end;
  for i:=1 to n do
    for j:=1 to m do
      if (a[i,j]='K') or (a[i,j]='B') then
        begin
          area:=0; t:=a[i,j];
          flood(i,j);
          if a[i,j]='K' then ak:=area
            else ab:=area;
        end;
  if ak=ab then writeln('SERI')
    else if ak>ab then writeln('K ',ak-ab)
      else writeln('B ',ab-ak);
end.

