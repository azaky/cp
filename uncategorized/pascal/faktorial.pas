var
  n,ans:longint;

begin
  readln(n); ans:=0;
  while n>0 do
    begin
      n:=n div 5;
      ans:=ans+n;
    end;
  writeln(ans);
end.

