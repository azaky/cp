var
  i,hasil1,hasil2:integer;
  input1,input2,abjad:string;

begin
  readln(input1);
  readln(input2);
  abjad:='ABCDEFGHIJKLMNOPQRSTUVWXYZ';
  hasil1:=1;
  hasil2:=1;
  for i:=1 to length(input1) do hasil1:=(hasil1*pos(input1[i],abjad)) mod 47;
  for i:=1 to length(input2) do hasil2:=(hasil2*pos(input2[i],abjad)) mod 47;
  if hasil1=hasil2 then writeln('GO') else writeln('STAY');
end.