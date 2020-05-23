var
  n,i,max,result:longint;
  w,b:array[1..10000] of longint;

function stack(i:longint):longint;
  var
    temp,j,max:longint;

  begin
    stack:=1;
    max:=0;
    for j:=1 to n do if (w[i]>w[j]) and (b[i]>b[j]) then
      begin
        temp:=stack(j);
        if temp>max then max:=temp;
      end;
    stack:=stack+max;
  end;

begin
  readln(n);
  for i:=1 to n do readln(w[i],b[i]);
  max:=0;
  for i:=1 to n do
    begin
      result:=stack(i);
      if result>max then max:=result;
    end;
  writeln(max);
end.
