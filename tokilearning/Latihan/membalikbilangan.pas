var
  n,i,t,j:longint;
  s:string;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(s);
      if s='0' then
        begin
          writeln(0);
          continue;
        end;
      t:=length(s);
      while s[t]='0' do dec(t);
      for j:=t downto 1 do write(s[j]);
      writeln;
    end;
end.
