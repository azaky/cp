var
  i,n,l,r:longint;
  total:int64;
  a,s,ans:array[0..300003] of longint;

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

begin
  readln(n);
  for i:=1 to n do read(s[i]);
  for i:=1 to n do read(a[i]);
  randomize; sort(1,n); l:=1; r:=n;
  fillchar(ans,sizeof(ans),255);
  for i:=2 to n-1 do
    begin
      if (s[i]<s[i-1]) and (s[i]<s[i+1]) then
        begin
          ans[i]:=a[l]; inc(l);
        end;
      if (s[i]>s[i-1]) and (s[i]>s[i+1]) then
        begin
          ans[i]:=a[r]; dec(r);
        end;
    end;
  if s[1]>s[2] then
    begin
      ans[1]:=a[r]; dec(r);
    end;
  if s[1]<s[2] then
    begin
      ans[1]:=a[l]; inc(l);
    end;
  if s[n]>s[n-1] then
    begin
      ans[n]:=a[r]; dec(r);
    end;
  if s[n]<s[n-1] then
    begin
      ans[n]:=a[l]; inc(l);
    end;
  for i:=2 to n-1 do
    begin
      if (s[i]>s[i-1]) and (s[i]<s[i+1]) then
        begin
          ans[i]:=a[l]; inc(l);
        end;
      if (s[i]<s[i-1]) and (s[i]>s[i+1]) then
        begin
          ans[i]:=a[r]; dec(r);
        end;
    end;
  total:=0;
  for i:=1 to n-1 do total:=total+int64(abs(ans[i]-ans[i+1]));
  writeln(total);
  for i:=1 to n-1 do write(ans[i],' ');writeln(ans[n]);
end.
