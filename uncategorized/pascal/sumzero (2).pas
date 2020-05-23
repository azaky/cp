type
  sets=array[1..2000] of longint;

var
  t,kasus,n,i,j:integer;
  count:longint;
  a,b,c:sets;

procedure qsort(var a:sets);
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
    sort(1,n);
  end;

function search(l,r,v:longint):boolean;
  begin
    if l=r then
      if c[l]=v then search:=true
        else search:=false
      else if c[(l+r) div 2]>=v then search:=search(l,(l+r) div 2,v)
        else search:=search(((l+r) div 2)+1,r,v);
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      for i:=1 to n do read(a[i]);
      for i:=1 to n do read(b[i]);
      for i:=1 to n do read(c[i]);
      qsort(a);
      qsort(b);
      qsort(c);
      count:=0;
      for i:=1 to n do
        for j:=1 to n do
          if search(1,n,(-a[i]-b[j])) then inc(count);
      writeln(count);
    end;
end.
