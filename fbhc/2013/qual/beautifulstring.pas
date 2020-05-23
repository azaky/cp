var
  ntc, itc, n, i, j, temp, ans : longint;
  s : ansistring;
  count : array[0..26] of longint;

begin
  readln(ntc);
  for itc := 1 to ntc do
    begin
      readln(s); n := length(s);
      fillchar(count,sizeof(count),0);
      for i := 1 to n do
        begin
          if (ord('a') <= ord(s[i])) and (ord(s[i]) <= ord('z')) then inc(count[ord(s[i])-ord('a')+1]);
          if (ord('A') <= ord(s[i])) and (ord(s[i]) <= ord('Z')) then inc(count[ord(s[i])-ord('A')+1]);
        end;
      for i := 1 to 25 do
        for j := 26 downto i+1 do
          if (count[j] < count[j-1]) then
            begin
              temp := count[j];
              count[j] := count[j-1];
              count[j-1] := temp;
            end;
      ans := 0;
      for i := 1 to 26 do ans := ans + i * count[i];
      writeln('Case #',itc,': ',ans);
    end;
end.
