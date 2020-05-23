var
  im,il,iw,response:integer;
  stat:boolean;

begin
  stat:=true;
  im:=1;
  il:=1;
  iw:=1;
  while stat do
    begin
      writeln(im,' ',il,' ',iw);
      flush(output);
      readln(response);
      if response=0 then stat:=false
        else if response=1 then inc(im)
          else if response=2 then inc(il)
            else if response=3 then inc(iw);
    end;
end.