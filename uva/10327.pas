var
  n,i,j,ans,temp:longint;
  a:array[0..111111] of longint;

begin
  repeat
    readln(n);
    for i:=1 to n do read(a[i]);readln;
    ans := 0;
    for i:=1 to n-1 do
      for j:=n downto i+1 do
        if a[j]<a[j-1] then
          begin
            temp := a[j]; a[j]:=a[j-1]; a[j-1] := temp; inc(ans);
          end;
    writeln('Minimum exchange operations : ',ans);
  until eof;
end.
