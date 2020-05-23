var
  i,n,p,th,len:longint;
  s:ansistring;
  id,pos,a,l,r,ans:array[0..11111] of longint;

procedure sort(l,r:longint);
  var
    i,j,mid,temp:longint;
  
  begin
    i:=l; j:=r; mid:=a[random(r-l+1)+l];
    repeat
      while a[i]<mid do inc(i);
      while a[j]>mid do dec(j);
      if i>j then break else temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
      temp:=id[i]; id[i]:=id[j]; id[j]:=temp;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;
  
begin
  repeat
    readln(s); len := length(s);
    if len=0 then continue;
    for i:=1 to len do
      if s[i] in ['0'..'9'] then a[0]:=10*a[0]+ord(s[i])-ord('0')
        else if s[i-1] in ['0'..'9'] then begin inc(n); a[n]:=a[0]; a[0]:=0; end;
    if s[len] in ['0'..'9'] then begin inc(n); a[n]:=a[0]; a[0]:=0; end;
  until eof;
  for i:=1 to n do id[i] := i;
  randomize; sort(1,n);
  for i:=1 to n do pos[id[i]] := i;
  for i:=0 to n+1 do begin l[i]:=i-1; r[i]:=i+1; end;
  p := (n+1) div 2; th := (n+1) div 2;
  for i:=n downto 1 do
    begin
      if i mod 2=0 then ans[i]:=(a[p]+a[r[p]]) div 2 else ans[i]:=a[p];
      l[r[pos[i]]]:=l[pos[i]]; r[l[pos[i]]]:=r[pos[i]];
      if pos[i]=p then p:=r[p]
        else if pos[i]<p then dec(th);
      if th<i div 2 then while th<i div 2 do begin inc(th); p:=r[p]; end;
      if th>i div 2 then while th>i div 2 do begin dec(th); p:=l[p]; end;
    end;
  for i:=1 to n do writeln(ans[i]);
end.
