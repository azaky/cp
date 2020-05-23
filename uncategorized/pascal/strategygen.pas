var
  t,i,n,j,k,l:longint;
  
begin
  randomize;
  assign(output,'strategy.txt');
  rewrite(output);
  
  t:=10;
  writeln(t);
  for i:=1 to t do
    begin
      n:=random(12)+1;
      //n:=12;
      writeln(n);
      for l:=1 to 3 do
        for j:=1 to n do
          begin
            k:=random(300)+1;
            if j=n then writeln(k:3)
              else write(k:3,' ');
          end;
      writeln; writeln;
    end;
  writeln;
  close(output);
  
  
end.

