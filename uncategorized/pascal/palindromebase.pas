var
  n,s,i,check,v:longint;
  stat:boolean;

function palbase(base,n:longint):boolean;
  var
    length,diff,temp,i:longint;
    result:array[1..1000] of integer;

  begin
    length:=0;
    diff:=n;
    while diff>0 do
      begin
        diff:=diff div base;
        inc(length);
      end;
    for i:=1 to length do
      begin
        temp:=n mod base;
        result[length+1-i]:=temp;
        n:=n div base;
      end;
    for i:=1 to length div 2 do
      if result[i]<>result[length+1-i] then
        begin
          palbase:=false;
          break;
        end
      else palbase:=true;
  end;

begin
  readln(n,s);
  v:=0;
  while s>0 do
    begin
      inc(s);
      check:=0;
      stat:=false;
      for i:=2 to 10 do
        begin
          if palbase(i,s) then inc(check);
          if check=2 then
            begin
              stat:=true;
              break;
            end
          else stat:=false;
        end;
      if stat then
        begin
          write(s,' ');
          for i:=2 to 10 do if palbase(i,s) then write(i,' ');
          writeln;
          inc(v);
        end;
      if v=n then s:=0;
    end;
end.