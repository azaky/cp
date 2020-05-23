var
  t,kasus,n,m,i:longint;
  s:array[1..80,1..3] of longint;
  id:array[0..80] of string[5];

procedure sort(l,r:longint);
  var
    i,j:longint;
    m,temp:array[1..3] of longint;
    tid:string[5];
  
  begin
    i:=l; j:=r; m:=s[(l+r) div 2];
    repeat
      while (s[i][3]>m[3]) or ((s[i][3]=m[3]) and (s[i][2]>m[2])) or ((s[i][3]=m[3]) and (s[i][2]=m[2]) and (s[i][1]>m[1])) do inc(i);
      while (s[j][3]<m[3]) or ((s[j][3]=m[3]) and (s[j][2]<m[2])) or ((s[j][3]=m[3]) and (s[j][2]=m[2]) and (s[j][1]<m[1])) do dec(j);
      if i>j then break;
      temp:=s[i]; s[i]:=s[j]; s[j]:=temp;
      tid:=id[i]; id[i]:=id[j]; id[j]:=tid;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n,m); readln(id[0]);
      for i:=1 to n do readln(id[i],s[i][1],s[i][2],s[i][3]);
      sort(1,n);
      for i:=1 to n do
        if id[i]=id[0] then
          begin
            if i<=m then writeln('YA')
              else writeln('TIDAK');
            break;
          end;
    end;
end.

