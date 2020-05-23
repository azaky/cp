var
  tc,kasus,n,i,ib,score:longint;
  a,b:array[0..1111] of longint;

procedure sort(var a:array of longint);
  var
    i,j,temp:longint;
  
  begin
    for i:=1 to n-1 do
      for j:=n downto i+1 do
        if a[j]<a[j-1] then
          begin
            temp := a[j]; a[j] := a[j-1]; a[j-1] := temp;
          end;
  end;

begin
  readln(kasus);
  for tc:=1 to kasus do
    begin
      readln(n);
      for i:=1 to n do read(a[i]);
      for i:=1 to n do read(b[i]);
      sort(a); sort(b);
      ib := 1; score := 0;
      for i:=1 to n do
        begin
          while (a[i]>=b[ib]) and (ib<=n) do inc(ib);
          if ib>n then break;
          inc(score); inc(ib);
        end;
      if 2*score > n then writeln('YA') else writeln('TIDAK');
    end;
end.
