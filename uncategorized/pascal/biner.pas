var
a,basis,i,hasil:integer;
temp:array[0..100] of integer;

function pangkat(x,y:longint):longint;

  begin
  if y=0 then pangkat:=1
    else pangkat:=pangkat(x,y-1)*x;
  end;

begin
write('Input the number = ');
readln(a);
write('Input the base number (2 to 16) = ');
readln(basis);
while (basis>16) or (basis<2) do
  begin
  writeln('Invalid base number. Please enter a number from 2 to 16.');
  readln(basis)
  end;
hasil:=-1;
i:=a;
while i>0 do
  begin
  i:=i div basis;
  inc(hasil);
  end;
for i:=hasil downto 0 do
  begin
  {pangkat:=1;
  if i=0 then pangkat:=1 else
  for j:=1 to i do pangkat:=2*pangkat;}
  if a>=pangkat(basis,i) then
    begin
    temp[i]:=a div pangkat(basis,i);
    a:=a mod pangkat(basis,i);
    end;
  end;
for i:=hasil downto 0 do
  begin
  if temp[i]=10 then write('A')
    else
    if temp[i]=11 then write('B')
      else
      if temp[i]=12 then write('C')
        else
        if temp[i]=13 then write('D')
          else
          if temp[i]=14 then write('E')
            else
            if temp[i]=15 then write('F')
              else write(temp[i]);
  end;
end.