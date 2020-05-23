var
  n,k,i,j,d:longint;
  task:string;
  a:array[0..1000000] of integer;

begin
  readln(n);
  k:=0;
  for i:=1 to n do
    begin
      readln(task);
      if task='pop_back' then
        begin
          a[k]:=0;
          dec(k);
        end
      else if task='pop_front' then
        begin
          for j:=1 to (k-1) do a[j]:=a[j+1];
          a[k]:=0;
          dec(k);
        end
      else if copy(task,1,9)='push_back' then
        begin
          val(copy(task,11,length(task)),d);
          inc(k);
          a[k]:=d;
        end
      else if copy(task,1,10)='push_front' then
        begin
          val(copy(task,12,length(task)),d);
          for j:=k downto 1 do a[j+1]:=a[j];
          inc(k);
          a[1]:=d;
        end;
    end;
  for i:=1 to k do writeln(a[i]);
end.