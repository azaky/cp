var
  tc,kasus,r,c,n,L,r0,c0,r1,c1,r2,c2,i,ans,area,width:longint;
  tab,range:array[0..111,0..111] of longint;
begin
  readln(tc);
  for kasus:=1 to tc do
    begin
      readln(r,c,n,L);
      fillchar(tab,sizeof(tab),255);
      for r0:=1 to r do
        for c0:=1 to c do tab[r0][c0]:=0;
      for i:=1 to n do
        begin
          readln(r1,c1,r2,c2);
          for r0:=r1 to r2 do
            for c0:=c1 to c2 do tab[r0][c0]:=-1;
        end;
      for r0:=1 to r do
        for c0:=c downto 1 do
          if tab[r0][c0]<0 then range[r0][c0]:=0
            else range[r0][c0]:=range[r0][c0+1]+1;
      ans := 0;
      for r0:=1 to r do
        for c0:=1 to c do
          begin
            width := maxlongint;
            area :=0;
            for i:=r0 to r do
              begin
                if range[i][c0]<width then width := range[i][c0];
                if width*(i-r0+1)>area then area := width*(i-r0+1);
              end;
            if area>ans then ans:=area;
          end;
      if ans<L then writeln('TIDAK') else writeln('YA');
    end;
end.
