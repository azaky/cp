var
  n,m,x,i,num:integer;
  stat:array[1..1000] of boolean;

procedure bebek;
  var
    count:integer;

  begin
    count:=0;
    while not(count=m) do
      begin
        inc(count);
        inc(num);
        if num>n then num:=num-n;
        while not(stat[num]) do if num<n then inc(num) else num:=1;
      end;
    stat[num]:=false;
  end;

begin
  readln(n,m,x);
  num:=0;
  for i:=1 to n do stat[i]:=true;
  for i:=1 to x do if i<n then bebek else break;
  for i:=1 to n do if stat[i] then writeln(i);
end.