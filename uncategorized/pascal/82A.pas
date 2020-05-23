var
  suit,r1,s1,r2,s2,space:char;
  map:array[chr(0)..chr(255)] of integer;

begin
  map['6']:=1; map['7']:=2; map['8']:=3; map['9']:=4; map['T']:=5; map['J']:=6; map['Q']:=7; map['K']:=8; map['A']:=9;
  readln(suit);
  read(r1,s1);
  repeat
    read(r2);
  until r2<>' ';
  read(s2);
  if ((s1=s2) and (map[r1]>map[r2])) or ((s1=suit) and (s2<>suit)) then writeln('YES')
    else writeln('NO');
end.
