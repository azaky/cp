var
  num1,num2,tempnum:string;
  n1,n2,sisa,x,k,i:integer;
  hasil:array[1..102] of byte;
  
begin
  fillchar(hasil,sizeof(hasil),0);
  readln(num1);
  readln(num2);
  if length(num1)<length(num2) then
    begin
      tempnum:=num1;
      num1:=num2;
      num2:=tempnum;
    end;
  n1:=length(num1);
  n2:=length(num2);
  sisa:=0;
  k:=0;
  while k<n1 do
    begin
      inc(k);
      x:=sisa+ord(num1[n1+1-k])-48;
      if k<=n2 then x:=x+ord(num2[n2+1-k])-48;
      hasil[k]:=x mod 10;
      if x>9 then sisa:=1
        else sisa:=0;
    end;
  if sisa=1 then write(1);
  for i:=k downto 1 do write(hasil[i]);
  writeln;
end.