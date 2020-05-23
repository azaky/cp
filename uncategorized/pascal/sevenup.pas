var
  m,n,i:longint;
  s,temp:string;
  stat:boolean;

begin
  readln(m);
  readln(n);
  str(n,s);
  for i:=1 to m do
    begin
      stat:=true;
      if i mod n=0 then stat:=false
        else
          begin
            str(i,temp);
            if pos(s,temp)<>0 then stat:=false;
          end;
      if stat then write(i) else write('boom');
      if i=m then writeln else write(' ');
    end;
end.