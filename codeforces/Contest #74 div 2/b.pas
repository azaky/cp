var
  n,m,i,j,k:longint;
  a:array[1..100,1..100] of char;
  v:array[1..100,1..100] of boolean;
  ans:ansistring;

begin
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do read(a[i,j]);
      readln;
    end;
  for i:=1 to n do
    for j:=1 to m do
      begin
        v[i,j]:=true;
        for k:=1 to n do
          if (k<>i) and (a[i,j]=a[k,j]) then
            begin
              v[i,j]:=false;
              break;
            end;
        if not v[i,j] then continue;
        for k:=1 to m do
          if (k<>j) and (a[i,j]=a[i,k]) then
            begin
              v[i,j]:=false;
              break;
            end;
      end;
  ans:='';
  for i:=1 to n do
    for j:=1 to m do
      if v[i,j] then ans:=ans+a[i,j];
  writeln(ans);
end.
