var
  n,m,soal,i,j,skor:longint;
  kunci,s:ansistring;

begin
  readln(n,m); soal:=n;
  readln(kunci);
  for i:=1 to n do
    if kunci[i]='-' then dec(soal);
  for i:=1 to m do
    begin
      readln(s); skor:=0;
      for j:=1 to n do
        if (kunci[j]<>'-') and (kunci[j]=s[j]) then inc(skor);
      writeln(100*skor/soal:0:2);
    end;
end.
