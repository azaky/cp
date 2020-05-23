var
  n,i,ans:longint;
  a,pos:array[-1..500005] of longint;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do pos[a[i]]:=i;
  for i:=1 to n do
    begin
      if (a[i]=0) or (a[i]=i) then continue;
      //swap a[i] and a[pos[a[i]]]
      a[pos[i]]:=a[i];
      pos[a[i]]:=pos[i];
      inc(ans);
    end;
  writeln(ans);
end.
