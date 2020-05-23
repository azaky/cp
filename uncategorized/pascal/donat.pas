var
  t,kasus,i,j,m,n,i1,j1,donat,area:integer;
  stat,stat2:array[0..101,0..101] of boolean;
  a:array[0..101,0..101] of char;
  input:string;

label
  finish;

procedure fill1(r,c:integer);
  var
    i,j:integer;

  begin
    if not(stat[r,c]) and (1<=r) and (r<=n) and (1<=c) and (c<=m) then
      begin
        inc(area);
        stat[r,c]:=true;
        stat2[r,c]:=true;
        for i:=r-1 to r+1 do
          for j:=c-1 to c+1 do
            if a[i,j]='1' then fill1(i,j);
      end;
  end;

procedure fill2(r,c:integer);
  begin
    if not stat2[r,c] and (1<=r) and (r<=n) and (1<=c) and (c<=m) then
      begin
        inc(area);
        stat2[r,c]:=true;
        fill2(r-1,c);
        fill2(r+1,c);
        fill2(r,c-1);
        fill2(r,c+1);
      end;
  end;

procedure fill0(r,c:integer);
  begin
    if not (stat2[r,c]) and (a[r,c]='0') and (1<=r) and (r<=n) and (1<=c) and (c<=m) then
      begin
        inc(area);
        stat2[r,c]:=true;
        fill0(r-1,c);
        fill0(r+1,c);
        fill0(r,c-1);
        fill0(r,c+1);
      end;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n,m);
      for i:=1 to n do
        begin
          readln(input);
          for j:=1 to m do a[i,j]:=input[j];
        end;
      fillchar(stat,sizeof(stat),false);
      donat:=0;
      for i:=1 to n do 
        for j:=1 to m do
          if (a[i,j]='1') and not (stat[i,j]) then
            begin
              area:=0;
              fillchar(stat2,sizeof(stat2),false);
              fill1(i,j);
              for i1:=1 to n do
                begin
                  if not stat2[i1,1] then fill2(i1,1);
                  if not stat2[i1,m] then fill2(i1,m);
                end;
              for j1:=1 to m do
                begin
                  if not stat2[1,j1] then fill2(1,j1);
                  if not stat2[n,j1] then fill2(n,j1);
                end;
              if area=m*n then goto finish;
              for i1:=1 to n do
                for j1:=1 to m do
                  if (a[i1,j1]='0') and not (stat2[i1,j1]) then
                    begin
                      fill0(i1,j1);
                      if area=m*n then inc(donat);
                      goto finish;
                    end;
              finish:
            end;
      writeln(donat);
    end;
end.