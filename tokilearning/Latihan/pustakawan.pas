var
  n,i,ans,p,temp:longint;
  s,a:array[1..1000] of longint;
  pos:array[-32768..32768] of longint;

procedure sort(l,r:longint);
  var
    i,j,mid,temp:longint;

  begin
    i:=l; j:=r; mid:=s[(l+r) div 2];
    repeat
      while s[i]<mid do inc(i);
      while s[j]>mid do dec(j);
      if i>j then break;
      temp:=s[i]; s[i]:=s[j]; s[j]:=temp;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  s:=a;
  sort(1,n);
  for i:=1 to n do pos[s[i]]:=i;
  i:=1; ans:=0;
  repeat
    while (a[i]=s[i]) and (i<=n) do inc(i);
    if i>n then break;
    while a[i]<>s[i] do
      begin
        inc(ans);
        p:=pos[a[i]];
        temp:=a[i]; a[i]:=a[p]; a[p]:=temp;
      end;
    inc(i);
  until i>n;
  writeln(ans);
end.
