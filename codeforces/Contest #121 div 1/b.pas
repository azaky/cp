var
  n,k,i,day,p:longint;
  x,idx,prev,next:array[-1..111111] of longint;
  a:array[-1..111111] of int64;
  b,worse:int64;
  used:array[-1..111111] of boolean;

procedure sort(l,r:longint);
  var
    i,j,p,midx,midi,temp:longint;
  
  begin
    i:=l; j:=r; p:=random(r-l+1)+l; midx:=x[p]; midi:=idx[p];
    repeat
      while (x[i]>midx) or ((x[i]=midx) and (idx[i]>midi)) do inc(i);
      while (x[j]<midx) or ((x[j]=midx) and (idx[j]<midi)) do dec(j);
      if i>j then break;
      temp:=x[i]; x[i]:=x[j]; x[j]:=temp;
      temp:=idx[i]; idx[i]:=idx[j]; idx[j]:=temp;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  readln(n,k);readln(b);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do x[i]:=a[i];
  for i:=1 to n do idx[i]:=i;
  randomize; sort(1,n);
  worse:=0;
  for i:=1 to k do worse:=worse+x[i];
  if b>=worse then
    begin
      writeln(n);halt;
    end;
  for i:=0 to n+1 do begin prev[i]:=i-1; next[i]:=i+1; end;
  i:=1;
  for day:=1 to k do
    begin
      while used[idx[i]] do inc(i);
      p := idx[i];
      
      if p=prev[n+1] then continue;
      if b>=a[p] then
        begin
          b:=b-a[p];
          used[p]:=true; next[prev[p]]:=next[p]; prev[next[p]]:=prev[p];
          p:=prev[n+1];
        end
      else b:=0;
    end;
  writeln(p);
end.
