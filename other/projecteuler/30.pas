var
  i,ans,temp,sc,total:longint;
  p:array[0..9] of longint;
  n:array[0..999999] of longint;

begin
  for i:=0 to 9 do p[i]:=i*i*i*i*i;
  ans:=0;
  for i:=10 to 999999 do
    begin
      temp:=i; sc:=0;
      while temp>0 do
        begin
          sc:=sc+p[temp mod 10]; temp:=temp div 10;
        end;
      if sc=i then
        begin
          inc(ans); n[ans]:=i;
        end;
    end;
  for i:=1 to ans do writeln(n[i]:10);
  writeln(ans);
  for i:=1 to ans do total:=total+n[i];
  writeln(total);
end.
