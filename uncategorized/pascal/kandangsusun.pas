var
  n,k,i,j,tinggi,max,s:longint;
  a:array[1..1000000] of integer;

begin
  readln(n,k);
  for i:=1 to n do readln(a[i]);
  tinggi:=1;
  for i:=1 to (n div k) do
    begin
      max:=0;
      for j:=1 to k do
        if a[(i-1)*k+j]>max then max:=a[(i-1)*k+j];
      tinggi:=tinggi+max+1;
    end;
  s:=n mod k;
  if s=0 then
    else
      begin
        max:=0;
        for j:=1 to s do
          if a[i*k+j]>max then max:=a[i*k+j];
        tinggi:=tinggi+max+1;
      end;
  writeln(tinggi);
end.