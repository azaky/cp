var
  empty, active:boolean;
  n,nn,depth,position,line,i,k:longint;
  exception,command,msg,exc,a:ansistring;

begin
  readln(nn); depth := 0; exception := '?';
  for line:=1 to nn do
    begin
      readln(a); n:=length(a);
      empty := true;
      for i:=1 to n do
        if a[i]<>' ' then empty := false;
      if empty then continue;
      command := '';
      for i:=1 to n do
        begin
          if a[i]=' ' then continue;
          if a[i]='t' then
            if a[i+1]='r' then
              begin
                command := 'try';
                k:=i+3;
                break;
              end
            else if a[i+1]='h' then
              begin
                command := 'throw';
                k:=i+5;
                break;
              end
            else
          else if a[i]='c' then
            begin
              command := 'catch';
              k:=i+5;
              break;
            end;
        end;
      i:=k;
      if command = 'try' then
        begin
          inc(depth); 
          //writeln('TRY ',depth);
          continue;
        end;
      if command = 'throw' then
        begin
          while (a[i]='(') or (a[i]=' ') do inc(i);
          exception := '';
          while (a[i] in ['a'..'z']) or (a[i] in ['A'..'Z']) do
            begin
              exception := exception + a[i];
              inc(i);
            end;
          position := depth;
          //writeln('THROW ',exception);
          continue;
        end;
      if command = 'catch' then
        begin
          while (a[i]='(') or (a[i]=' ') do inc(i);
          exc := '';
          while (a[i] in ['a'..'z']) or (a[i] in ['A'..'Z']) do
            begin
              exc := exc + a[i];
              inc(i);
            end;
          while not (a[i]='"') do inc(i);
          inc(i); msg := '';
          while not (a[i]='"') do
            begin
              msg := msg + a[i];
              inc(i);
            end;
          if (exception = exc) and (depth <= position) and not active then
            begin
              active := true;
              writeln(msg);
            end;
          if depth = position then dec(position);
          dec(depth);
          //writeln('CATCH ',exc,':',msg);
        end;
    end;
  if not active then writeln('Unhandled Exception');
end.
