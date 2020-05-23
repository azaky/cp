var
  n,m,k,x,i,ans,a1,b1:longint;
  hash,val:array[1..200005] of longint;
  a,b:array[1..100005] of longint;

procedure sort(l,r:longint);
  var
    i,j,mid,temp:longint;
    
  begin
    i:=l;
    j:=r;
    mid:=hash[(l+r) div 2];
    repeat
      while hash[i]<mid do inc(i);
      while hash[j]>mid do dec(j);
      if i<=j then
        begin
          temp:=hash[i];
          hash[i]:=hash[j];
          hash[j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

function index(z:longint):longint;
  var
    l,r:longint;
    
  begin
    l:=1;
    r:=x;
    while true do
      begin
        if hash[(l+r) div 2]<=z then l:=(l+r) div 2
          else r:=(l+r) div 2;
        if hash[l]=z then exit(l);
        if hash[r]=z then exit(r);
      end;
  end;

begin
  readln(n,m,k);
  x:=0;
  for i:=1 to m do
    begin
      readln(a[i],b[i]);
      inc(b[i]);
      inc(x);
      hash[x]:=a[i];
      inc(x);
      hash[x]:=b[i];
    end;
  sort(1,x);
  x:=1;
  for i:=2 to 2*m do
    if hash[i]<>hash[i-1] then
      begin
        inc(x);
        hash[x]:=hash[i];
      end;
  writeln;
  for i:=1 to m do
    begin
      a1:=index(a[i]);
      b1:=index(b[i]);
      inc(val[a1]);
      dec(val[b1]);
    end;
  for i:=2 to x do val[i]:=val[i]+val[i-1];
  ans:=0;
  for i:=1 to x do
    if val[i]>k then ans:=ans+hash[i+1]-hash[i];
  writeln(ans);
end.

