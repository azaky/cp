var
  n,i,k,temp,j:longint;

begin
  readln(n);
  for i:=1 to trunc(exp(n*ln(2)))-1 do
    begin
      k:=1; temp:=i;
      while temp mod 2=0 do
        begin
          inc(k);
          temp:=temp div 2;
        end;
      for j:=1 to k do write('*');
      writeln;
    end;
end.

