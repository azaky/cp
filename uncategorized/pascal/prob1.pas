var
  n,m,i,num1,num2,t:longint;
  a,b:array[1..100000] of longint;

procedure swap(var num1,num2:longint);
  var
    temp:longint;

  begin
    temp:=num1;
    num1:=num2;
    num2:=temp;
  end;

begin
  readln(n,m);
  for i:=1 to n do a[i]:=i;
  for i:=1 to m do
    begin
      readln(num1,num2);
      swap(a[num1],a[num2]);
    end;
  readln(t);
  for i:=1 to t do readln(b[i]);
  for i:=1 to t do writeln(a[b[i]]);
end.