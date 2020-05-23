{
ID: a_zaky01
PROG: ride
LANG: PASCAL
}

const
  abjad='ABCDEFGHIJKLMNOPQRSTUVWXYZ';

var
  i,val1,val2:integer;
  str1,str2:string;
  fin,fout:text;

begin
  assign(fin,'ride.in');
  assign(fout,'ride.out');
  reset(fin);
  rewrite(fout);
  readln(fin,str1);
  readln(fin,str2);
  val1:=1;
  val2:=1;
  for i:=1 to length(str1) do val1:=(val1*pos(str1[i],abjad)) mod 47;
  for i:=1 to length(str2) do val2:=(val2*pos(str2[i],abjad)) mod 47;
  if val1=val2 then writeln(fout,'GO') else writeln(fout,'STAY');
  close(fin);
  close(fout);
end.
