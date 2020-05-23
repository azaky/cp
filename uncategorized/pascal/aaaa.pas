{
var
  i,n:longint;
  hasil:real;

begin
  readln(n);
  hasil:=1;
  if n=0 then writeln(1)
    else
      begin
        for i:=1 to n do hasil:=hasil+(ln(i)/ln(10));
        writeln(trunc(hasil));
      end;
end.
}

var
  i,n:longint;
  hasil:real;

begin
  readln(n);
  hasil:=0;
  i:=0;
  while true do
    begin
      inc(i);
      hasil:=hasil+ln(i);
      if hasil>n*ln(10) then break;
    end;
  writeln(i-1);
end.
