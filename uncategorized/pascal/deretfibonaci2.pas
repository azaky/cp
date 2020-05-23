var
  n,i,temp1,temp2,f:qword;

begin
  readln(n);
  i:=1;
  temp1:=0;
  temp2:=1;
  while i>0 do
    begin
      if i=1 then f:=0
        else if i=2 then f:=1
          else f:=temp1+temp2;
      if f<n then
        begin
          inc(i);
          temp1:=temp2;
          temp2:=f;
        end
      else if f=n then
        begin
          writeln(i);
          i:=0;
        end
      else
        begin
          writeln('0');
          i:=0;
        end;
    end;
end.