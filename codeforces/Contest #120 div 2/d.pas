uses math;

var
  n,k,i,np:longint;
  a,p,next,prev,last,sum,nextk:array[-1..411111] of longint;
  ans:int64;

procedure sort(l,r:longint);
  var
    i,j,temp,mid:longint;
  begin
    i := l; j := r; mid := a[random(r-l+1)+l];
    repeat
      while a[i]<mid do inc(i);
      while a[j]>mid do dec(j);
      if i>j then break else temp := a[i]; a[i] := a[j]; a[j] := temp;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;
function search(x:longint):longint;
  var
    mid,l,r:longint;
  begin
    l:=1;r:=np;
    repeat
      mid:=(l+r) div 2;
      if a[mid]=x then exit(mid);
      if a[mid]>x then r:=mid-1 else l:=mid+1;
    until false;
  end;

begin
  readln(n,k);
  //if k=1 then begin writeln(int64(n)*int64(n+1) div 2);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do p[i] := a[i];
  randomize; sort(1,n); np := 0;
  for i:=1 to n do
    if a[i]<>a[i-1] then
      begin
        inc(np); a[np] := a[i];
      end;
  for i:=1 to n do p[i]:=search(p[i]);
  for i:=1 to n do a[i]:=p[i];
  for i:=n downto 1 do
    begin
      next[last[a[i]]] := i; prev[i] := last[a[i]];
      last[a[i]] := i; sum[i] := sum[prev[i]]+1;
    end;
  fillchar(last,sizeof(last),0);
  for i:=1 to n+5 do nextk[i] := maxlongint;
  for i:=n downto 1 do
    begin
      if last[a[i]]=0 then last[a[i]] := i;
      if sum[i]-sum[last[a[i]]]=k-1 then
        begin
          nextk[i] := last[a[i]];
          last[a[i]] := next[last[a[i]]];
        end;
    end;
  //for i:=1 to n do writeln(i:5,a[i]:10,nextk[i]:12);
  ans:=0;
  for i:=n downto 1 do
    begin
      nextk[i] := min(nextk[i+1],nextk[i]);
      if nextk[i]>n then continue;
      ans := ans + int64(n-nextk[i]+1);
    end;
  writeln(ans);
end.
