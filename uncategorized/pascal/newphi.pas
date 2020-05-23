var
  n,i:longint;
  q:array[2..10000000] of longint;

procedure factorize(n:longint);
  var
    j:longint;

  begin
    i:=2;
    if n=1 then
      else while n<>1 do
        begin
          while n mod i <> 0 do inc(i);
          n:=n div i;
          inc(q[i]);
        end;
  end;

function phi(n:longint):longint;
  var
    j:longint;

  begin
    factorize(n);
    phi:=n;
    for j:=i downto 2 do if q[j]<>0 then phi:=(phi*(j-1)) div j;
  end;

begin
  readln(n);
  writeln(phi(n));
end.