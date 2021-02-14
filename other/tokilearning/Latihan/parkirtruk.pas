var
  i,j,x,y,ans:longint;
  a:array[0..3] of longint;
  t:array[0..100] of longint;

begin
  readln(a[1],a[2],a[3]);
  a[2]:=2*a[2]; a[3]:=3*a[3]; a[0]:=0;
  for i:=1 to 3 do
    begin
      readln(x,y);
      for j:=x+1 to y do inc(t[j]);
    end;
  ans:=0;
  for i:=1 to 100 do ans:=ans+a[t[i]];
  writeln(ans);
end.
