var
n:string;
zero:boolean;
i,num1,num2:byte;
z,sum:qword;

begin
  readln(n);
  zero:=true;
  write('f(',n,') = ',n,' + ');
  for i:=length(n) downto 1 do
    if n[i]<>'0' then write(n[i]);
  write(' = ');
  z:=1;
  sum:=0;
  for i:=1 to length(n) do
    begin
      val(n[i],num1);
      val(n[length(n)+1-i],num2);
      sum:=z*num1+z*num2+sum;
      z:=z*10;
    end;
  writeln(sum);
end.
