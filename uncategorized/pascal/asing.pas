var
  a,b,c:int64;

begin
  readln(a,b,c);
  if (b-a)*(c-a)<=0 then writeln(a)
    else if (a-b)*(c-b)<=0 then writeln(b)
      else writeln(c);
end.

