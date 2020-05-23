var
  t,n,m,i,h,p:longint;
  temp:string;

begin
  randomize;
  for t:=1 to 10 do
    begin
      str(t,temp);
      temp:='testcase'+temp+'.in';
      assign(output,temp);
      rewrite(output);
      n:=random(1000)+1;
      m:=random(51)+150;
      writeln(n,' ',m);
      for i:=1 to n do
        begin
          h:=random(1000)+1;
          writeln(h);
        end;
      close(output);
    end;
end.
