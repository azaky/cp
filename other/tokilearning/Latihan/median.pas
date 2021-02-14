var
  n,i,a,m,na,b:longint;
  num:array[-8000..8000] of longint;

begin
  readln(n);
  for i:=1 to n do
    begin
      read(a); inc(num[a]);
    end;
  a:=(n+1) div 2; b:=(n+2) div 2;
  m:=0;
  for i:=-8000 to 8000 do
    begin
      inc(m,num[i]);
      if m>=a then
        begin
          a:=maxlongint;
          na:=i;
        end;
      if m>=b then
        begin
          writeln((na+i)/2:0:2);
          halt;
        end;
    end;
end.
