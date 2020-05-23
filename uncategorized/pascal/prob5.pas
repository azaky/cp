var
  n,m,x,i,bebek,count:integer;
  stat:array[1..1000] of boolean;

begin
  readln(n,m,x);
  for i:=1 to n do stat[i]:=true;
  bebek:=0;
  for i:=1 to x do
    begin
      count:=0;
      while count<>m do
        begin
          bebek:=(bebek mod n)+1;
          while not(stat[bebek]) do bebek:=(bebek mod n)+1;
          inc(count);
        end;
      stat[bebek]:=false;
    end;
  for i:=1 to n do
    if stat[i] then writeln(i);
end.
