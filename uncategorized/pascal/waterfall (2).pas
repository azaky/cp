var
  r,c,n,i,j,max,x,y:longint;
  x1,y1,x2,y2,f:array[0..1000] of longint;
  batu:array[0..501,0..501] of longint;

procedure sort(l,r:longint);
  var
    i,j,p,temp:longint;

  begin
    i:=l;
    j:=r;
    p:=y1[(l+r) div 2];
    repeat
      while y1[i]<p do inc(i);
      while y1[j]>p do dec(j);
      if i<=j then
        begin
          temp:=x1[i];
          x1[i]:=x1[j];
          x1[j]:=temp;
          temp:=x2[i];
          x2[i]:=x2[j];
          x2[j]:=temp;
          temp:=y1[i];
          y1[i]:=y1[j];
          y1[j]:=temp;
          temp:=y2[i];
          y2[i]:=y2[j];
          y2[j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  readln(r,c,n);
  for i:=1 to n do readln(y1[i],x1[i],y2[i],x2[i]);
  sort(1,n);
  for i:=1 to n do
    for j:=x1[i] to x2[i] do batu[j,y1[i]]:=i;
  for i:=n downto 1 do
    begin
      f[i]:=1;
      if x1[i]-1>0 then
        begin
          x:=x1[i]-1;
          y:=y2[i]+1;
          while (batu[x,y]=0) and (y<=r) do inc(y);
          if y<=r then f[i]:=f[i]+f[batu[x,y]];
        end;
      if x2[i]+1<=c then
        begin
          x:=x2[i]+1;
          y:=y2[i]+1;
          while (batu[x,y]=0) and (y<=r) do inc(y);
          if y<=r then f[i]:=f[i]+f[batu[x,y]];
        end;
    end;
  max:=0;
  i:=1;
  while i<=c do
    begin
      y:=1;
      while (batu[i,y]=0) and (y<=r) do inc(y);
      if y<=r then
        begin
          if f[batu[i,y]]>max then max:=f[batu[i,y]];
          i:=i+1+x2[batu[i,y]]-x1[batu[i,y]];
        end
      else inc(i);
    end;
  writeln(max);
end.
