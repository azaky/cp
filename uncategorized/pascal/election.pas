var
  t,kasus,n,m,i,j,num:longint;
  vote:array[1..5] of longint;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n,m);
      fillchar(vote,sizeof(vote),0);
      for i:=1 to m do
        for j:=1 to n do
          begin
            read(num);
            inc(vote[j],num);
          end;
      j:=1;
      for i:=2 to n do
        if vote[i]>vote[j] then j:=i;
      writeln(j);
    end;
end.