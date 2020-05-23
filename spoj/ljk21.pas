var
  n,k,i,j,ans:longint;
  sudoku:boolean;
  a:array[1..1000000] of longint;
  c:array[1..50] of longint;

begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-k+1 do
    begin
      sudoku:=true; fillchar(c,sizeof(c),0);
      for j:=i to i+k-1 do
        begin
          inc(c[a[j]]);
          if c[a[j]]=2 then
            begin
              sudoku:=false;
              break;
            end;
        end;
      if sudoku then inc(ans);
    end;
  writeln(ans);
end.
