var
  n,i,j,ages,nu,q,num:longint;
  exist:boolean;
  age,reg,temp:array[1..1000] of longint;

begin
  readln(n);
  for i:=1 to n do
    begin
      read(age[i]);
      readln(reg[i]);
    end;
  readln(q);
  exist:=false;
  num:=1;
  for i:=1 to n do
    begin
      if reg[i]=q then
        begin
          exist:=true;
          ages:=age[i];
        end;
      if not(exist) then temp[i]:=-1
        else
          begin
            if age[i]>ages then inc(num);
            temp[i]:=num;
          end;
    end;
  if not(exist) then writeln('ERROR')
    else for i:=1 to n do writeln(temp[i]);
end.
