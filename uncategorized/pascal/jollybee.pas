var
  t,kasus,i,j,n,m,count,temp:longint;
  p:array[0..10] of integer;
  av:array[1..1024] of boolean;

begin
  readln(t);
  p[0]:=1;
  for i:=1 to 10 do p[i]:=p[i-1]*2;
  for kasus:=1 to t do
    begin
      readln(n,m);
      fillchar(av,sizeof(av),true);
      for i:=1 to m do
        begin
          read(temp);
          av[temp]:=false;
        end;
      count:=0;
      for i:=n downto 1 do
        for j:=1 to p[i-1] do
          begin
            if (av[2*j-1] and not av[2*j]) or (not av[2*j-1] and av[2*j]) then inc(count);
            av[j]:=av[2*j-1] or av[2*j];
          end;
      writeln(count);
    end;
end.
