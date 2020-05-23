var
  n,k,error,ans,i:longint;
  a,last:array[0..1000000] of longint;

begin
  readln(n,k); error:=0;
  for i:=1 to n do
    begin
      read(a[i]);
      if last[a[i]]>error then error:=last[a[i]];
      last[a[i]]:=i;
      if error=i-k then inc(ans);
    end;
  writeln(ans);
end.
