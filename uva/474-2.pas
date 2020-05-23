var
  n,ten,i:longint;
  ans:array[0..1111111] of extended;

begin
  ans[0] := 1;
  for i:=1 to 1000000 do
    begin
      ans[i] := ans[i-1]*5;
      if ans[i]>10 then ans[i] := ans[i]/10;
    end;
  repeat
    readln(n);
    ten := trunc(n*ln(2)/ln(10))+1;
    writeln('2^-',n,' = ',ans[n]:0:3,'e-',ten);
  until eof;
end.
