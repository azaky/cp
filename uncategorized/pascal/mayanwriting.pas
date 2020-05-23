var
  g,s,i,j,k,count:longint;
  glyphs,seq:string;
  statseq,statglyphs:boolean;
  stat:array[1..3000] of boolean;

begin
  readln(g,s);
  readln(glyphs);
  readln(seq);
  count:=0;
  for i:=1 to (s+1-g) do
    begin
      for j:=1 to g do stat[j]:=false;
      statseq:=true;
      for j:=i to i+g-1 do
        begin
          statglyphs:=false;
          for k:=1 to g do
            if not(stat[k]) and (seq[j]=glyphs[k]) then
              begin
                statglyphs:=true;
                stat[k]:=true;
                break;
              end;
          if not(statglyphs) then
            begin
              statseq:=false;
              break;
            end;
        end;
      if statseq then inc(count);
    end;
  writeln(count);
end.
