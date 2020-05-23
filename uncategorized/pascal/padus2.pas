var
  m,n,each,add,i:longint;
  a:array[1..10002] of longint;
  duck:array[1..20] of longint;

procedure sort(l,r:longint);
  var
    i,j,mid,temp:longint;
  
  begin
    i:=l; j:=r; mid:=a[(l+r) div 2];
    repeat
      while a[i]<mid do inc(i);
      while a[j]>mid do dec(j);
      if i>j then break else temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

procedure sing(pos,group,left:longint);
  var
    i:longint;
  
  begin
    if (left<0) or (n-group<left) then exit;
    if pos=m then
      begin
        for i:=1 to n-2 do write(a[duck[i]]+1,' ');
        writeln(a[duck[n-1]]+1);
      end;
    inc(group);
    duck[group]:=pos+each;
    if a[duck[group]]<>a[duck[group]+1] then sing(pos+each,group,left);
    duck[group]:=pos+each+1;
    if a[duck[group]]<>a[duck[group]+1] then sing(pos+each+1,group,left-1);
  end;

begin
  readln(m);
  for i:=1 to m do readln(a[i]);
  readln(n); sort(1,m); a[m+1]:=maxlongint; a[m+2]:=maxlongint;
  for i:=1 to m do write(a[i],' '); writeln; writeln;
  each:=m div n; add:=m-n*each;
  sing(0,0,add);
end.

