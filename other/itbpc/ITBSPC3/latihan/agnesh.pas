var
  s,sans: ansistring;
  skorans,skor,p: int64;
  i,n: longint;

begin
  skorans := -1;
  while not eof do
    begin
      readln(s);
      n := length(s);
      skor := 0; p := 1;
      for i := n downto 1 do
        begin
          if (48 <= ord(s[i])) and (ord(s[i]) <= 57) then
            begin
              skor := skor + p*(ord(s[i])-48);
              p := p * 10;
            end
          else break;
        end;
      while (s[i] = ' ') do dec(i);
      s := copy(s,1,i);
      if (skor > skorans) then
        begin
          sans := s; skorans := skor;
        end;
    end;
  writeln(sans);
end.
