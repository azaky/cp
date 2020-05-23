var
  s:ansistring;
  n,i,len,j:longint;
  pal:array[0..2002,0..2002] of boolean;
  countl:array[0..2002] of int64;
  ans:int64;

begin
  readln(s); n:=length(s);
  for i:=1 to n do pal[i,i]:=true;
  for i:=1 to n-1 do
    if s[i]=s[i+1] then pal[i,i+1]:=true;
  for len:=3 to n do
    begin
      for i:=1 to n-len+1 do
        if (s[i]=s[i+len-1]) and pal[i+1,i+len-2] then pal[i,i+len-1]:=true;
    end;
  for i:=1 to n do
    begin
      countl[i]:=countl[i-1];
      for j:=1 to i do
        if pal[j][i] then inc(countl[i]);
    end;
  for i:=n downto 2 do
    for j:=i downto 2 do
      if pal[j,i] then ans:=ans+countl[j-1];
  writeln(ans);
end.
