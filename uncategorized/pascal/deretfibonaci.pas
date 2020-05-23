var
  n,i:qword;
  a:array[0..100000] of qword;

begin
  readln(n);
  a[0]:=1;
  a[1]:=0;
  i:=1;
  if n=0 then writeln('1') else if n=1 then writeln('1') else
    begin
      while a[i]<n do
        begin
          inc(i);
          a[i]:=a[i-1]+a[i-2];
        end;
      if a[i]=n then writeln(i) else writeln('0');
    end;
end.