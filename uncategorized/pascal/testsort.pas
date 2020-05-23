var
  fname:string;
  t,u:int64;
  sorted:boolean;

begin
  readln(fname);
  assign(input,fname); reset(input);
  readln(t); sorted:=true;
  while not eof do
    begin
      readln(u);
      if u<t then
        begin
          sorted:=false;
          break;
        end
      else t:=u;
    end;
  writeln(sorted);
end.

