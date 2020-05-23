var
  n,i,k:longint;
  a,b:array[1..100000] of longint;

procedure sort;
  var
    i,j:longint;

  procedure swap(var int1,int2:longint);
    var
      temp:longint;

    begin
      temp:=int1;
      int1:=int2;
      int2:=temp;
    end;

  begin
    for i:=2 to n do
      for j:=1 to i-1 do
        if a[j]>a[j+1] then swap(a[j],a[j+1]);
  end;

begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  sort;
  k:=(1+n) div 2;
  b[1]:=a[k];
  for i:=n downto (k+1) do b[2*(n+1-i)]:=a[i];
  for i:=1 to (k-1) do b[2*i+1]:=a[i];
  for i:=1 to n do writeln(b[i]);
end.