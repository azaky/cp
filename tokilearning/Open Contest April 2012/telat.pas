var
  tc,kasus,n,k,i,job:longint;
  possible:boolean;
  l,count:array[-1..1000000] of longint;

begin
  readln(tc);
  for kasus:=1 to tc do
    begin
      readln(n,k);
      for i:=1 to n*k do read(l[i]);
      possible := true; job := 0;
      fillchar(count,sizeof(count),0);
      for i:=1 to n*k do
        begin
          inc(count[l[i]]);
          if l[i]>1 then
            if count[l[i]-1]=0 then
              begin
                possible := false; break
              end
            else dec(count[l[i]-1]);
          if l[i]=k then inc(job);
        end;
      if (job=n) and possible then writeln(1) else writeln(0);
    end;
end.
