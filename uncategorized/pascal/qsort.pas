var
  n,i:integer;
  a:array[1..10000] of integer;

procedure sort(l,r:longint);
  var
    i,j,x,temp:integer;

  begin
    i:=l;
    j:=r;
    x:=a[(l+r) div 2];
    repeat
      while a[i]<x do inc(i);
      while a[j]>x do dec(j);
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
  readln(n);
  for i:=1 to n do read(a[i]);
  sort(1,n);
  for i:=1 to n do if i<n then write(a[i],' ') else writeln(a[i]);
end.
