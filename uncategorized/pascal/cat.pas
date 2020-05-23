var
  n,m,k,x,i,a,b,ans:longint;
  hash,val:array[1..200005] of longint;

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
          temp:=val[i];
          val[i]:=val[j];
          val[j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  readln(n,m,k);
  x:=0;
  for i:=1 to m do
    begin
      readln(a,b);
      inc(x);
      hash[x]:=a;
      val[x]:=1;
      inc(x);
      hash[x]:=b+1;
      val[x]:=-1;
    end;
  sort(1,x);
  x:=1;
  for i:=2 to 2*m do
    if hash[i]=hash[i-1] then
      val[x]:=val[x]+val[i]
    else
      begin
        inc(x);
        hash[x]:=hash[i];
        val[x]:=val[i]+val[x-1];
      end;
  ans:=0;
  for i:=1 to x do
    if val[i]>k then ans:=ans+hash[i+1]-hash[i];
  writeln(ans);
end.

