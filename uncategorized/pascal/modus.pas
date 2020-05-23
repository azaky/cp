var
  n,i,j,max,count,temp,modus:longint;
  a:array[1..1000000] of longint;
  stat:array[1..1000000] of boolean;

begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  max:=0;
  for i:=1 to n do
    if not(stat[i]) then
      begin
        temp:=a[i];
        count:=1;
        for j:=i+1 to n do
          if a[j]=temp then
            begin
              inc(count);
              stat[j]:=false;
            end;
        if count>max then
          begin
            modus:=a[i];
            max:=count;
          end
        else if count=max then
          if a[i]<modus then modus:=a[i];
      end;
  writeln(modus);
end.
