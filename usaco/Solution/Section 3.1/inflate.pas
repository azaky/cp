{
ID: a_zaky01
PROG: inflate
LANG: PASCAL
}

var
  m,n,i,j:longint;
  p,t,max:array[0..10000] of longint;
 
procedure sort(l,r:integer);
  var
    i,j,mid,temp:integer;
    
  begin
    i:=l;
    j:=r;
    mid:=t[(l+r) div 2];
    repeat
      while t[i]<mid do inc(i);
      while t[j]>mid do dec(j);
      if i<=j then
        begin
          if i<j then
            begin
              temp:=t[i];
              t[i]:=t[j];
              t[j]:=temp;
              temp:=p[i];
              p[i]:=p[j];
              p[j]:=temp;
            end;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;
 

begin
  assign(input,'inflate.in');
  assign(output,'inflate.out');
  reset(input);
  rewrite(output);
  readln(m,n);
  for i:=1 to n do readln(p[i],t[i]);
  sort(1,n);
  for i:=1 to m do
    for j:=1 to n do
      if t[j]<=i then
        if max[i]<max[i-t[j]]+p[j] then max[i]:=max[i-t[j]]+p[j];
  writeln(max[m]);
  close(input);
  close(output);
end.
