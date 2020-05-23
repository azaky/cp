var
  n,i,j,k,ng,maxmove:integer;
  ch:char;
  ed:array[1..2] of integer;
  a,aprev:array[0..11,0..11] of integer;
  tg:array[-1..3,1..2] of integer;
  right,rightprev:array[-1..3] of boolean;
  now,prev:array[0..11,0..11] of boolean;

begin
  readln(n);
  fillchar(a,sizeof(a),255);
  fillchar(prev,sizeof(prev),false);
  for i:=1 to n do
    for j:=1 to n do
      begin
        read(ch);
        if ch='S' then
          begin
            prev[i,j]:=true;
            a[i,j]:=0;
          end
        else if ch='T' then
          begin
            ed[1]:=i; ed[2]:=j;
            a[i,j]:=0;
          end
        else if ch='X' then
          begin
            inc(ng); tg[ng][1]:=i; tg[ng][2]:=j;
            right[ng]:=true;
            a[i,j]:=ng;
          end
        else if ch='#' then a[i,j]:=-1 else a[i,j]:=0;
        if j=n then readln;
      end;
  for i:=1 to ng do
    begin
      if right[i] and (a[tg[i][1],tg[i][2]+1]<0) then right[i]:=false;
      if not right[i] and (a[tg[i][1],tg[i][2]-1]<0) then right[i]:=true;
    end;
  maxmove:=n*n*6;
  for k:=1 to maxmove do
    begin
      aprev:=a; rightprev:=right;
      for i:=1 to ng do
        begin
          if right[i] and (a[tg[i][1],tg[i][2]+1]=0) then
            begin
              a[tg[i][1],tg[i][2]]:=0;
              inc(tg[i][2]);
              a[tg[i][1],tg[i][2]]:=i;
              if a[tg[i][1],tg[i][2]+1]<0 then right[i]:=false;
            end
          else if not right[i] and (a[tg[i][1],tg[i][2]-1]=0) then
            begin
              a[tg[i][1],tg[i][2]]:=0;
              dec(tg[i][2]);
              a[tg[i][1],tg[i][2]]:=i;
              if a[tg[i][1],tg[i][2]-1]<0 then right[i]:=true;
            end;
        end;
      {
      for i:=1 to n do
        begin
          for j:=1 to n do if a[i,j]>=0 then write(a[i,j]) else write('.');
          writeln;
        end;
      writeln(right[1]);writeln;
      }
      for i:=1 to n do
        for j:=1 to n do
          begin
            if (a[i,j]<>0) then
              begin
                now[i,j]:=false; continue;
              end
            else now[i,j]:=prev[i,j] or prev[i-1,j] or prev[i+1,j] or (prev[i,j-1] and not((aprev[i,j]>0) and not rightprev[aprev[i,j]])) or (prev[i,j+1] and not((aprev[i,j]>0) and rightprev[aprev[i,j]]));
          end;
      if now[ed[1],ed[2]] then
        begin
          writeln(k); halt;
        end
      else prev:=now;
    end;
  writeln(-1);
end.

