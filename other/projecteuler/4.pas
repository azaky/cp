var
  max,a,b,n,i:longint;
  temp:string;
  valid:boolean;

begin
  max:=0;
  for a:=101 to 999 do
    for b:=a to 999 do
      begin
        n:=a*b; str(n,temp); valid:=true;
        for i:=1 to length(temp) do
          if temp[i]<>temp[length(temp)+1-i] then
            begin
              valid:=false;
              break;
            end;
        if valid and (n>max) then max:=n;
      end;
  writeln(max);
end.
