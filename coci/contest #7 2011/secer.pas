var
  n,i,best:integer;
  way:array[0..5000] of longint;
  
begin
  readln(n);
  fillchar(way,sizeof(way),255);
  way[3]:=1; way[5]:=1;
  for i:=6 to n do
    begin
      best:=10000;
      if (way[i-3]>0) and (way[i-3]<best) then best:=way[i-3];
      if (way[i-5]>0) and (way[i-5]<best) then best:=way[i-5];
      if best=10000 then way[i]:=-1
        else way[i]:=best+1;
    end;
  writeln(way[n]);
end.

