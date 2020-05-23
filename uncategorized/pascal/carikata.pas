var
  n,i,j,m:integer;
  s:string;
  d,k:array[1..1000] of string;
  
procedure qsort(l,r:integer);
  var
    i,j:integer;
    mid,temp:string;
  
  begin
    i:=l; j:=r; mid:=d[(l+r) div 2];
    repeat
      while d[i]<mid do inc(i);
      while d[j]>mid do dec(j);
      if i>j then break;
      temp:=d[i]; d[i]:=d[j]; d[j]:=temp;
      inc(i); dec(j);
    until i>j;
    if l<j then qsort(l,j);
    if i<r then qsort(i,r);
  end;

function sorted(t:string):string;
  var
    s:string;
    
  procedure sort(l,r:integer);
    var
      i,j:integer;
      mid,temp:char;
    
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
    s:=t;
    sort(1,length(s));
    exit(s);
  end;

begin
  readln(n);
  for i:=1 to n do readln(d[i]);
  qsort(1,n);
  for i:=1 to n do k[i]:=sorted(d[i]);
  readln(m);
  for i:=1 to m do
    begin
      readln(s);
      s:=sorted(s);
      for j:=1 to n do
        if s=k[j] then writeln(d[j]);
      writeln('--');
    end;
end.

