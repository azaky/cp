var
  start,finish,n,i,j,temp:longint;
  time:array[1..1000000] of boolean;
  yes,no:array[1..1000000] of longint;

function max(a:array of longint):longint;
  var
    temp:longint;

  begin
    temp:=0;
    for i:=1 to 1000000 do if a[i]>temp then max:=a[i];
  end;

begin
  readln(n);
  for i:=1 to 1000000 do time[i]:=false;
  for i:=1 to n do
    begin
      readln(start,finish);
      for j:=start to finish do time[j]:=true;
    end;
  for i:=1 to 1000000 do
    if time[i] then
      begin
        temp:=0;
        j:=i;
        while temp=0 do
          begin
            if time[j] then inc(j)
              else inc(temp);
          end;
        j:=j-i;
        yes[i]:=j;
      end
    else
      begin
        temp:=0;
        j:=i;
        while temp=0 do
          begin
            if not(time[j]) then inc(j)
              else inc(temp);
          end;
        j:=j-i;
        no[i]:=j;
      end;
  writeln(max(yes),' ',max(no));
end.