var
  r,c,n,i,j,x,y:longint;
  max:int64;
  x1,y1,x2,y2:array[1..100000] of longint;
  f:array[0..100000] of int64;
  batu:array[0..501,0..501] of int64;

procedure swap(var a,b:longint);
  var
    temp:longint;

  begin
    temp:=a;
    a:=b;
    b:=temp;
  end;

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
          swap(x1[i],x1[j]);
          swap(x2[i],x2[j]);
          swap(y1[i],y1[j]);
          swap(y2[i],y2[j]);
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
          if y<=r then inc(f[i],f[batu[x,y]]);
        end;
      if x2[i]+1<=c then
        begin
          x:=x2[i]+1;
          y:=y2[i]+1;
          while (batu[x,y]=0) and (y<=r) do inc(y);
          if y<=r then inc(f[i],f[batu[x,y]]);
        end;
    end;
  max:=0;
  for
  writeln(max);
end.
