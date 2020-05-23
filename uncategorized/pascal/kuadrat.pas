var
  n,temp:longint;

begin
  readln(n);
  temp:=trunc(sqrt(n));
  if n=1 then writeln(0)
    else if temp*temp=n then writeln(temp)
      else writeln(0)
end.
