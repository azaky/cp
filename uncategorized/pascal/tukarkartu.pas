var
  n,ans,i,j,max:longint;
  a:array[0..1000] of longint;

procedure swap(var a,b:longint);
  var
    temp:longint;
  
  begin
    temp:=a; a:=b; b:=temp;
  end;

begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  ans:=0; a[0]:=-1000000;
  for i:=n downto 1 do
    begin
      max:=0;
      for j:=i downto 1 do
        if a[j]>a[max] then max:=j;
      if max=i then continue;
      for j:=max to i-1 do swap(a[j],a[j+1]);
      ans:=ans+i-max;
    end;
  writeln(ans);
end.

