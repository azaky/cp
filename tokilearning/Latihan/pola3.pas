var
  n,k,i:integer;

begin
  readln(n,k);
  if k=1 then write('*')
    else write('1');
  for i:=2 to n do
    if i mod k=0 then write(' *')
      else write(' ',i);
  writeln;
end.