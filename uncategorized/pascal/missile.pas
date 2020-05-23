var
  n,m,i,j,count,awal,akhir:longint;
  home:array[1..100000] of integer;
  stat:array[1..100000] of boolean;

begin
  readln(n,m);
  for i:=1 to n do read(home[i]);
  for j:=1 to m do
    begin
      readln(awal,akhir);
      for i:=1 to n do
        if not(stat[i]) and (awal<=home[i]) and (home[i]<=akhir) then
          begin
            inc(count);
            stat[i]:=true;
            break;
          end;
    end;
  writeln(count);
end.
