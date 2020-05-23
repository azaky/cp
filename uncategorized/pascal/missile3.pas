var
  i,j,n,m,count:longint;
  home,awal,akhir:array[1..1000] of longint;
  stat:array[1..1000] of boolean;
  
procedure sorth(l,r:longint);
  var
    i,j,p,temp:longint;
  
  begin
    i:=l;
    j:=r;
    p:=home[(l+r) div 2];
    repeat
      while home[i]<p do inc(i);
      while home[j]>p do dec(j);
      if not(i>j) then
        begin
          temp:=home[i];
          home[i]:=home[j];
          home[j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sorth(l,j);
    if i<r then sorth(i,r);
  end;
  
procedure sortm(l,r:longint);
  var
    i,j,p,temp:longint;
  
  begin
    i:=l;
    j:=r;
    p:=awal[(l+r) div 2];
    repeat
      while awal[i]<p do inc(i);
      while awal[j]>p do dec(j);
      if not(i>j) then
        begin
          if awal[i]=awal[j] then
            if akhir[i]>akhir[j] then
              begin
                temp:=akhir[j];
                akhir[j]:=akhir[i];
                akhir[i]:=temp;
              end
            else
          else
            begin
              temp:=awal[i];
              awal[i]:=awal[j];
              awal[j]:=temp;
              temp:=akhir[i];
              akhir[i]:=akhir[j];
              akhir[j]:=temp;
            end;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sortm(l,j);
    if i<r then sortm(i,r);
  end;

begin
  readln(n,m);
  for i:=1 to n do read(home[i]);
  for i:=1 to m do readln(awal[i],akhir[i]);
  sorth(1,n);
  sortm(1,m);
  count:=0;
  for i:=m downto 1 do
    for j:=n downto 1 do
      if not stat[j] then
        if (home[j]>=awal[i]) and (home[j]<=akhir[i]) then
          begin
            inc(count);
            stat[j]:=true;
            break;
          end;
  writeln(count);
end.