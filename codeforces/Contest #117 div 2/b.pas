var
  d,date,ans:int64;
  a:array[0..2222] of int64;
  n,i:longint;

begin
  readln(d);
  readln(n);
  for i:=1 to n do read(a[i]);
  ans:=0; date:=1;
  for i:=1 to n do
    begin
      //change the clock to 1
      if date>1 then
        begin ans:=ans+d-date+1; date:=1; end;
      date:=date+a[i];
      if date>d then date:=date-d;
    end;
  writeln(ans);
end.
