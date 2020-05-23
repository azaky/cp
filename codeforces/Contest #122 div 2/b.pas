var
  tc,kasus:longint;
  ans,n:int64;

begin
  readln(tc);
  for kasus:=1 to tc do
    begin
      read(n);
      ans := n;
      while ((n+1)*ans) mod (4*n) <> 0 do ans := ans*2;
      writeln(ans+1);
    end;
end.
