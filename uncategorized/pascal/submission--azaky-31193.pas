var
  v,h,n,i,j,vt,ht:longint;
  l,r,ans:int64;
  v1,v2,h1,h2:array[1..100000] of longint;
  batu:array[0..501,0..501] of longint;
  f:array[1..100000] of int64;
 
procedure sort(l,r:longint);
  var
    i,j,p,temp:longint;
  
  begin
    i:=l;
    j:=r;
    p:=v1[(l+r) div 2];
    repeat
      while v1[i]<p do inc(i);
      while v1[j]>p do dec(j);
      if i<=j then
        begin
          if i<>j then
            begin
              temp:=v1[i];
              v1[i]:=v1[j];
              v1[j]:=temp;
              temp:=v2[i];
              v2[i]:=v2[j];
              v2[j]:=temp;
              temp:=h1[i];
              h1[i]:=h1[j];
              h1[j]:=temp;
              temp:=h2[i];
              h2[i]:=h2[j];
              h2[j]:=temp;
            end;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;
 
begin
  readln(v,h,n);
  for i:=1 to n do readln(v1[i],h1[i],v2[i],h2[i]);
  sort(1,n);
  for i:=1 to n do
    for j:=h1[i] to h2[i] do batu[v1[i],j]:=i;
  for i:=n downto 1 do
    begin
      l:=0;
      r:=0;
      if h1[i]-1>0 then
        begin
          vt:=v2[i]+1;
          ht:=h1[i]-1;
          while (vt<=v) and (batu[vt,ht]=0) do inc(vt);
          if vt<=v then l:=f[batu[vt,ht]];
        end;
      if h2[i]+1<=h then
        begin
          vt:=v2[i]+1;
          ht:=h2[i]+1;
          while (vt<=v) and (batu[vt,ht]=0) do inc(vt);
          if vt<=v then r:=f[batu[vt,ht]];
        end;
      f[i]:=l+r+1;
    end;
  ans:=0;
  for ht:=1 to h do
    begin
      vt:=0;
      while (vt<=v) and (batu[vt,ht]=0) do inc(vt);
      if vt<=v then
        if f[batu[vt,ht]]>ans then ans:=f[batu[vt,ht]];
    end;
  writeln(ans);
end.
 