var
  n,i,j:longint;
  p,q:array[1..1000000] of longint;

begin
  readln(n);
  if n=1 then writeln(n)
    else
      begin
        i:=2;
        while n<>1 do
          begin
            while n mod i <> 0 do inc(i);
            n:=n div i;
            p[i]:=i;
            inc(q[i]);
          end;
        for j:=i downto 1 do if q[j]<>0 then writeln(p[j],' ',q[j]);
      end;
end.
