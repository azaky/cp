var
  n,i:longint;
  a,b:int64;
  s:array[0..211111] of string[4];

begin
  readln(n); a:=1; b:=1;
  for i:=1 to n do readln(s[i]);
  for i:=n downto 1 do
    if s[i]='UL' then inc(a)
    else if s[i]='UR' then inc(b)
    else if s[i]='DL' then inc(b)
    else if s[i]='DR' then inc(a)
    else if s[i]='ULDR' then
      begin
        inc(a);inc(b);
      end;
  writeln(a*b);
end.
