var
  n,q,i,j:integer;
  input,friend:string;
  nama,nomor,temp:array[1..10000] of string;

begin
  readln(n,q);
  for i:=1 to n do
    begin
      readln(input);
      for j:=1 to length(input) do if input[j]=' ' then break;
      nama[i]:=copy(input,1,j-1);
      nomor[i]:=copy(input,j+1,length(input));
    end;
  for i:=1 to q do
    begin
      readln(friend);
      for j:=1 to n do if friend=nama[j] then
        begin
          temp[i]:=nomor[j];
          break;
        end;
    end;
  for i:=1 to q do writeln(temp[i]);
end.