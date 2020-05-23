var
  t,kasus,i,n,m,sum,k:longint;
  a:array[1..10000] of longint;

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
      readln(n,m);
      sum:=0;
      for i:=1 to n do
        begin
          read(a[i]);
          sum:=sum+a[i];
        end;
      if sum<=m then writeln(-1)
        else
          begin
            sort(1,n);
            i:=0;
            sum:=0;
            while true do
              begin
                inc(i);
                sum:=sum+a[i];
                if sum+(n-i)*a[i]>=m then
                  begin
                    k:=(sum+(n-i)*a[i]-m) div (n+1-i);
                    if (sum+(n-i)*a[i]-m) mod (n+1-i)<>0 then inc(k);
                    writeln(a[i]-k);
                    break;
                  end;
              end;
          end;
    end;
end.
