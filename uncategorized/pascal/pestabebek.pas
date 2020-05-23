var
  i,n,j,k:longint;
  s:string;
  guest:array[0..1000] of string;
  
begin
  readln(n); guest[0]:='';
  for i:=1 to n do
    begin
      readln(s);
      for j:=1 to length(s) do
        if s[j]<>' ' then s[j]:=upcase(s[j]);
      if s>=guest[i-1] then
        begin
          guest[i]:=s;  writeln(i);
          continue;
        end;
      for j:=i-1 downto 1 do
        if (guest[j-1]<=s) and (s<=guest[j]) then
          begin
            for k:=i downto j+1 do guest[k]:=guest[k-1];
            guest[j]:=s; writeln(j);
            break;
          end;
    end;
end.

