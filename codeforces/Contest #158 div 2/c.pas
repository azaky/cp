var
  n,x,i,pos,t:longint;
  dis : int64;
  a:array[0..211111] of int64;

begin
  readln(n,x);
  for i := 1 to n do read(a[i]);
  pos := x;
  for i := x downto 1 do
    if a[i] < a[pos] then pos := i;
  for i := n downto x+1 do
    if a[i] < a[pos] then pos := i;
  dis := int64(x - pos); if dis < 0 then dis := dis + int64(n);
  dis := dis + a[pos]*int64(n);
  
  if x < pos then inc(x,n);
  
//  writeln(dis,' ',pos);
  
  for i := pos + 1 to pos + n-1 do
    begin
      t := i; if (t > n) then t := t - n;
      if (i <= x) then a[t] := a[t] - (dis div n) - 1
      else a[t] := a[t] - (dis div n);
    end;
  
  a[pos] := dis;
  
  for i := 1 to n do write(a[i],' ');
end.
