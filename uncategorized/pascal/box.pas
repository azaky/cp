const
  max=100000;
  dom=1000000007;

var
  j,n,t:longint;
  i,temp:int64;
  arr:array[1..max+1] of int64;

begin
  arr[1]:=1;
  for j:=2 to max do
    begin
      i:=j;
      if i mod 2=0 then temp:=((i div 2)*(i-1)) mod dom
        else temp:=(i*((i-1) div 2)) mod dom;
      arr[i]:=(arr[i-1]*temp) mod dom;
    end;
  readln(t);
  for j:=1 to t do
    begin
      readln(n);
      writeln(arr[n]);
    end;
end.
