var
  a,b,n,num,sisa,i:longint;
  ans:array[0..111111] of longint;

begin
  readln(a,b,n);
  num := a;
  for i := 1 to n do
    begin
      num := (10 * num) mod b;
      sisa := b - num;
      if (sisa = b) then sisa := 0;
      if (sisa < 10) then
        begin
          ans[i] := sisa;
          num := num + sisa;
        end
      else
        begin
          writeln(-1); halt;
        end;
    end;
  write(a);
  for i := 1 to n do write(ans[i]);
  writeln;
end.
