var
  n,i:longint;
  stat:boolean;

begin
  readln(n);
  if n=1 then writeln('true')
    else
      begin
        stat:=false;
        for i:=2 to trunc(sqrt(n)) do
          if n mod (i*i)=0 then
            begin
              stat:=true;
              break;
            end;
        if stat then writeln('false') else writeln('true');
      end;
end.