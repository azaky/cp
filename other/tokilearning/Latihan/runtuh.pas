var
  r,c,i,j,count,p:integer;
  ch:char;
  demolish:boolean;
  a:array[0..20,1..8] of boolean;

begin
  readln(r,c);
  for i:=1 to r do
    begin
      for j:=1 to c do
        begin
          read(ch);
          a[i,j]:=(ch='1');
        end;
      readln;
    end;
  repeat
    demolish:=false;
    for i:=r downto 1 do
      begin
        count:=0;
        for j:=1 to c do
          if a[i,j] then inc(count);
        if count=c then
          begin
            demolish:=true;
            fillchar(a[i],sizeof(a[i]),false);
          end
        else if demolish then
          for j:=1 to c do
            if a[i,j] then
              begin
                p:=i;
                while (p<r) and not a[p+1,j] do
                  begin
                    a[p+1,j]:=true;
                    a[p,j]:=false;
                    inc(p);
                  end;
              end;
      end;
  until not demolish;
  for i:=1 to r do
    begin
      for j:=1 to c do
        if a[i,j] then write(1)
          else write(0);
      writeln;
    end;
end.
