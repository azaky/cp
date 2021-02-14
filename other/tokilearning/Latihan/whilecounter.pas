var
jumlah,bil:integer;

begin
jumlah := 0;
while not eof(input) do
begin
   readln(bil);
   jumlah := jumlah + bil;
end;
writeln(jumlah);

end.
