var
  n,i,j,home,sr,sc,cur,best,next,curmax,curmin:longint;
  ch:char;
  r,c:array[1..2500] of longint;
  max,min,val:array[1..50,1..50] of longint;
  visit:array[1..2500] of boolean;

procedure fill(r,c:longint);
  var
    qtake,qsave,i,j,tempmax,tempmin:longint;
    queue:array[1..2000000,1..2] of longint;
    wait:array[0..51,0..51] of boolean;
    
  begin
    fillchar(wait,sizeof(wait),false);
    fillchar(min,sizeof(min),255);
    fillchar(max,sizeof(max),255);
    qtake:=1;
    qsave:=1;
    queue[1][1]:=r;
    queue[1][2]:=c;
    min[r,c]:=val[r,c];
    max[r,c]:=val[r,c];
    while qtake<=qsave do
      begin
        r:=queue[qtake][1];
        c:=queue[qtake][2];
        wait[r,c]:=false;
        for i:=r-1 to r+1 do
          for j:=c-1 to c+1 do
            if (i<>r) or (j<>c) then
              begin
                if (i<1) or (i>n) or (j<1) or (j>n) then continue;
                tempmin:=val[i,j];
                tempmax:=val[i,j];
                if min[r,c]<tempmin then tempmin:=min[r,c];
                if max[r,c]>tempmax then tempmax:=max[r,c];
                if (min[i,j]<0) or (tempmax-tempmin<max[i,j]-min[i,j]) then
                  begin
                    max[i,j]:=tempmax;
                    min[i,j]:=tempmin;
                  end;
                if not wait[i,j] then
                  begin
                    wait[i,j]:=true;
                    inc(qsave);
                    queue[qsave][1]:=i; queue[qsave][2]:=j;
                  end;
              end;
        inc(qtake);
      end;
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      for j:=1 to n do
        begin
          read(ch);
          if ch='P' then
            begin
              sr:=i; sc:=j;
            end
          else if ch='K' then
            begin
              inc(home);
              r[home]:=i; c[home]:=j;
            end;
        end;
      readln;
    end;
  for i:=1 to n do
    for j:=1 to n do read(val[i,j]);
  
  fill(sr,sc);
  best:=1000001;
  cur:=-1;
  for i:=1 to home do
    if max[r[i],c[i]]-min[r[i],c[i]]<best then
      begin
        best:=max[r[i],c[i]]-min[r[i],c[i]];
        cur:=i;
      end;
  curmax:=max[r[cur],c[cur]];
  curmin:=min[r[cur],c[cur]];
  visit[cur]:=true;
  
  for i:=1 to home-1 do
    begin
      fill(r[cur],c[cur]);
      best:=1000001;
      next:=-1;
      for j:=1 to home do
        if not visit[j] then
          if max[r[j],c[j]]-min[r[j],c[j]]<best then
            begin
              best:=max[r[j],c[j]]-min[r[j],c[j]];
              next:=j;
            end;
      cur:=next;
      visit[cur]:=true;
      if curmax<max[r[cur],c[cur]] then curmax:=max[r[cur],c[cur]];
      if curmin>min[r[cur],c[cur]] then curmin:=min[r[cur],c[cur]];
    end;
  
  writeln(curmax-curmin);
  
end.
