var
  n,m,i,j,total,count,temp,temptotal:longint;
  home,awal,akhir:array[1..100000] of integer;
  stath,statm:array[1..100000] of boolean;

begin
  readln(n,m);
  for i:=1 to n do read(home[i]);
  for j:=1 to m do readln(awal[j],akhir[j]);
  while true do
    begin
      for j:=1 to m do
        if not(statm[j]) then
          begin
            count:=0;
            for i:=1 to n do
              if not(stath[i]) and (awal[j]<=home[i]) and (home[i]<=akhir[j]) then
                begin
                  inc(count);
                  temp:=i;
                end;
            if count=1 then
              begin
                statm[j]:=true;
                stath[temp]:=true;
                inc(total);
              end
            else if count=0 then statm[j]:=true;
          end;
      if temptotal=total then break
        else temptotal:=total;
    end;
  if total<n then
    for j:=1 to m do
      if not(statm[j]) then
        for i:=1 to n do
          if not(stath[i]) and (awal[j]<=home[i]) and (home[i]<=akhir[j]) then
            begin
              inc(total);
              stath[i]:=true;
            end;
  writeln(total);
end.
