var
  st:string;
  f:text;
  
begin
  assign(f,'/home/zaky/koding/presch/Test Cases/balance/tc1.txt');
  reset(f);
  //erase(f);
  readln(f,st); writeln(st);
  close(f);
end.

