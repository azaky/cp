const
  max=7;

var
  temp,temp2,i:byte;
  p,j:int64;
  a:array[1..max] of byte;
  f:text;

begin
  assign(f,'tes.out');
  rewrite(f);
  for i:=1 to max do a[i]:=0;
  p:=1;
  for i:=1 to max do p:=2*p;
  j:=0;
  while j<p do
    begin
      for i:=1 to max do write(f,a[i]);
      writeln(f);
      temp2:=1;
      for i:=max downto 1 do
        begin
          temp:=a[i];
          temp:=temp+temp2;
          if temp=2 then
            begin
              temp:=0;
              temp2:=1;
            end
          else temp2:=0;
          a[i]:=temp;
        end;
      inc(j);
    end;
  close(f);
end.
