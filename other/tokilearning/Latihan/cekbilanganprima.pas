var
  n,i:longint;
  prime:boolean;

begin
  while not eof do
    begin
      readln(n);
      if n<2 then
        begin
          writeln('TIDAK');
          continue;
        end;
      prime:=true;
      for i:=2 to trunc(sqrt(n)) do
        if n mod i=0 then
          begin
            prime:=false;
            break;
          end;
      if prime then writeln('YA')
        else writeln('TIDAK');
    end;
end.
