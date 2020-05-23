var
  t,kasus,i,len:integer;
  input:char;
  str:ansistring;
  
begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(str);
{
      str:='';
      while true do
        begin
          read(input);
          if (input<>'a') and (input<>'b') and (input<>'c') then break;
          str:=str+input;
        end;
}
      while true do
      begin
      len:=length(str);
      i:=1;
      while i<=length(str) do
        begin
          if i<=length(str)-2 then
            if str[i]=str[i+2] then delete(str,i,2)
              else inc(i)
          else inc(i);
        end;
      if len=length(str) then break;
      end;
      writeln(length(str));
    end;
end.