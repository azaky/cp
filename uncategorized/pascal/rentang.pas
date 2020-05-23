var
  t,kasus,n,i:longint;
  ans:int64;
  a:array[1..100000] of longint;

procedure sort(l,r:longint);
  var
    i,j,p,temp:longint;
  
  begin
    i:=l;
    j:=r;
    p:=a[(l+r) div 2];
    repeat
      while a[i]<p do inc(i);
      while a[j]>p do dec(j);
      if not(i>j) then
        begin
          temp:=a[i];
          a[i]:=a[j];
          a[j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      for i:=1 to n do read(a[i]);
      sort(1,n);
      ans:=0;
      i:=1;
      while (a[i]-1<=ans) and (i<=n) do
        begin
          ans:=ans+a[i];
          inc(i);
        end;
      writeln(ans);
    end;
end.
