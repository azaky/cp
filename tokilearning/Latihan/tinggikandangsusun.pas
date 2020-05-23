var
  n,k,i,j,max,a:longint;
  ans:int64;

begin
  readln(n,k);
  max:=0; ans:=0;
  for i:=1 to n do
    begin
      if (i-1) mod k=0 then
        begin
          ans:=ans+max+1;
          max:=0;
        end;
      readln(a);
      if a>max then max:=a;
    end;
  ans:=ans+max+1;
  writeln(ans);
end.
