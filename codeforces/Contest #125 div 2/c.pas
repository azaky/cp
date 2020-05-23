var
  k,b,n,t,ans,x:int64;

begin
  readln(k,b,n,t);
  ans := 0; x := 1;
  while x<=t do
    begin
      inc(ans); x := k*x+b; //writeln(x);
    end;
  writeln(x,' ',ans);
  if n-ans+1<0 then writeln(0) else writeln(n-ans+1);
end.
