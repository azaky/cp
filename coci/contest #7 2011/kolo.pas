var
  n,k,pos,i,m:integer;
  valid:boolean;
  ch:char;
  wheel:array[0..24] of char;
  
begin
  readln(n,k);
  pos:=0;
  fillchar(wheel,sizeof(wheel),'?');
  for i:=1 to k do
    begin
      read(m);
      repeat
        read(ch);
      until ch<>' ';
      pos:=(pos+m) mod n;
      if wheel[pos]='?' then wheel[pos]:=ch
        else if wheel[pos]<>ch then
          begin
            writeln('!');
            halt;
          end;
    end;
  for i:=pos+n downto pos+1 do write(wheel[i mod n]);
  writeln;
end.

