var
  n,i,j,k:longint;
  same:boolean;
  a,b,t:array[1..75,1..75] of integer;

begin
  readln(n,a[1,1]);
  for i:=1 to n do
    for j:=1 to n do read(a[i,j]);
  readln(b[1,1],b[1,2]);
  for i:=1 to n do
    for j:=1 to n do read(b[i,j]);
  for k:=0 to 3 do
    begin
      same:=true;
      for i:=1 to n do
        for j:=1 to n do
          if a[i,j]<>b[i,j] then same:=false;
      if same then
        begin
          writeln(k*90);
          break;
        end
      else if k=3 then
        begin
          writeln('tidak sama');
          break;
        end;
      for i:=1 to n do
        for j:=1 to n do t[i,j]:=a[n+1-j,i];
      a:=t;
    end;
end.
