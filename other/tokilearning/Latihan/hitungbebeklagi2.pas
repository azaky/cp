var
  n,i,j,np,aa,bb,ip,temp:longint;
  q,a,ans:array[0..111111] of longint;

procedure sort(l,r:longint);
  var
    i,j,mid,temp:longint;
  begin
    i:=l; j:=r; mid:=a[random(r-l+1)+l];
    repeat
      while a[i]<mid do inc(i);
      while a[j]>mid do dec(j);
      if i>j then break else temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

function search(x:longint):longint;
  var
    l,r,mid:longint;
  begin
    l:=1; r:=np;
    repeat
      mid := (l+r) div 2;
      if x=a[mid] then exit(mid);
      if x<a[mid] then r:=mid-1 else l:=mid+1;
    until false;
  end;

begin
  readln(n);
  for i:=1 to n do readln(q[i]);
  for i:=1 to n do a[i]:=q[i];
  randomize;sort(1,n);
  np:=1;
  for i:=2 to n do
    if a[i]>a[i-1] then
      begin
        inc(np); a[np]:=a[i];
      end;
  aa:=1; bb:=1; ip:=1;
  for i:=1 to 10000000 do
    begin
      bb:=(aa+bb) mod 1000000; aa:=(bb-aa+1000000) mod 1000000;
      if i=a[ip] then
        begin
          ans[ip]:=aa; inc(ip);
        end;
    end;
  for i:=1 to n do
    begin
      temp := ans[search(q[i])];
      if q[i]<30 then begin writeln(temp); continue; end;
      for j:=1 to 5-trunc(ln(temp)/ln(10)) do write(0);
      writeln(temp);
    end;
end.
