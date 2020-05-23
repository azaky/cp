var
  field:array[1..20000,1..20000] of string;
  stat:array[1..20000,1..20000] of boolean;
  r,c,i,j,k,l,input,home,x,y:integer;

begin
  readln(r,c);
  for i:=1 to c do
    for j:=1 to r do
      begin
        stat[i,j]:=false;
        writeln('ask ',i,' ',j,' ',i,' ',j);
        flush(output);
        readln(input);
        if input=1 then field[i,j]:='X' else field[i,j]:='.';
      end;
  home:=0;
  for i:=1 to c do
    for j:=1 to r do
      if field[i,j]='X' then
        if not(stat[i,j]) then
          begin
            x:=i;
            y:=j;
            while (field[x,j]='X') or (field[i,y]='X') do
              begin
                if field[x,j]='X' then inc(x);
                if field[i,y]='X' then inc(y);
              end;
            for k:=i to x-1 do
              for l:=j to y-1 do
                stat[k,l]:=true;
            inc(home);
            if home=(c*r+1) div 2 then break;
          end;
  writeln('answer ',home);
  exit;
end.
