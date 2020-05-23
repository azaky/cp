var
  n,m,i,j,ans,i1,j1,count,k,ians,jans:longint;
  a:array[1..100,1..100] of byte;
  stat,fix:array[0..9] of boolean;
  win:char;

begin
  readln(n,m);
  for i:=1 to n do
    for j:=1 to n do read(a[i,j]);
  ans:=m*m;
  for i:=1 to n-m+1 do
    for j:=1 to n-m+1 do
      begin
        fillchar(stat,sizeof(stat),false);
        count:=0;
        for i1:=i to i+m-1 do
          for j1:=j to j+m-1 do
            if not stat[a[i1,j1]] then
              begin
                stat[a[i1,j1]]:=true;
                inc(count);
              end;
        if ans>count then
          begin
            for i1:=0 to 9 do fix[i1]:=stat[i1];
            ans:=count;
            ians:=i;
            jans:=j;
          end
        else if ans=count then
          begin
            k:=9;
            win:='x';
            while k>=0 do
              begin
                if stat[k] and not fix[k] then
                  begin
                    win:='N';
                    break;
                  end
                else if not stat[k] and fix[k] then
                  begin
                    win:='O';
                    break;
                  end;
                dec(k);
              end;
            if win='N' then
              begin
                ians:=i;
                jans:=j;
                for i1:=0 to 9 do fix[i1]:=stat[i1];
              end;
          end;
      end;
  writeln(ians,' ',jans);
end.
