var
  c,i:longint;
  s:ansistring;
  pal:boolean;
  ch:char;

begin
  c:=0;
  while not eof do
    begin
      inc(c);
      s:='';
      repeat
        read(ch);
        if ch in ['a'..'z'] then s:=s+ch
          else break;
      until false;
      if s='' then continue;
      pal:=true;
      for i:=1 to length(s) div 2 do
        if s[i]<>s[length(s)+1-i] then
          begin
            pal:=false;
            break;
          end;
      if pal then
        if c=1 then write(s)
          else write(' ',s);
    end;
  writeln;
end.
