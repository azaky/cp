var
  n,k,i,temp1,temp2:integer;
  kartu:array[1..255] of string;

begin
  readln(n);
  readln(k);
  for i:=1 to k do readln(kartu[i]);
  for i:=2 to k do
    begin
      val(copy(kartu[i],1,1),temp1);
      val(copy(kartu[i-1],1,1),temp2);
      if temp1<temp2 then break;
    end;
  write(i);
end.