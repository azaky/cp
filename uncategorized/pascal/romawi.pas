var
  input:string;
  i,temp,temp2:integer;

procedure romawi(var k,n:integer);
  var
    satu,lima:array[1..4] of string;
    i:integer;

  begin
    satu[1]:='I'; satu[2]:='X'; satu[3]:='C'; satu[4]:='M';
    lima[1]:='V'; lima[2]:='L'; lima[3]:='D';
    if (n>0) and (n<4) then
      begin
        for i:=1 to n do write(satu[k]);
      end;
    if n=4 then write(satu[k],lima[k]);
    if (n>4) and (n<9) then
      begin
        write(lima[k]);
        for i:=1 to n-5 do write(satu[k]);
      end;
    if n=9 then write(satu[k],satu[k+1]);
  end;

begin
  readln(input);
  for i:=1 to length(input) do
    begin
      val(input[i],temp);
      temp2:=length(input)+1-i;
      romawi(temp2,temp);
    end;
  writeln;
end.
