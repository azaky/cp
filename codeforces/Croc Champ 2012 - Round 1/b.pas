type
  data = record
    r,c,dir:longint;
  end;

var
  n,m,i,j,p,temp,qtake,qsave,d,v:longint;
  s:ansistring;
  now:data;
  col:array[-1..1111,-1..1111] of boolean;
  next:array[-1..1111,-1..1111,1..4] of data;
  val:array[-1..1111,-1..1111,1..4] of longint;
  used:array[-1..1111,-1..1111,1..4] of boolean;
  queue:array[0..4444444] of data;

begin
  readln(n,m);
  for i:=1 to n do
    begin
      readln(s);
      for j:=1 to m do col[i,j]:=s[j]='#';
    end;
  inc(m); col[n,m]:=true;
  for i:=1 to n do
    begin
      p:=0;
      while p<=m do
        begin
          temp:=p; inc(p);
          while (p<=m) and (not col[i,p]) do inc(p);
          next[i,temp][3].r:=i; next[i,temp][3].c:=p;
          next[i,p][1].r:=i; next[i,p][1].c:=temp;
        end;
    end;
  for i:=1 to m do
    begin
      p:=0;
      while p<=n do
        begin
          temp:=p; inc(p);
          while (p<=n) and (not col[p,i]) do inc(p);
          next[temp,i][4].r:=p; next[temp,i][4].c:=i;
          next[p,i][2].r:=temp; next[p,i][2].c:=i;
        end;
    end;
  qtake:=1; qsave:=1;
  with queue[1] do
    begin
      r:=n; c:=m; dir:=1;
      val[r,c,dir]:=0;
      {
		  * directions:
		  * 1 = left
		  * 2 = up
		  * 3 = right
		  * 4 = down
	  }
    end;
  repeat
    now:=queue[qtake]; d:=now.dir; v:=val[now.r,now.c,now.dir];
    //with now do writeln(r,' ',c,' ',dir);
    if (now.dir=1) and (now.r=1) then
      begin
        writeln(v); halt;
      end;
    while true do
      begin
        now:=next[now.r,now.c][d];
        if not((now.r>0) and (now.r<=n) and (now.c>0) and (now.c<=m)) then break;
        for i:=1 to 4 do
          if not used[now.r,now.c,i] then
            begin
              used[now.r,now.c,i]:=true;
              val[now.r,now.c,i]:=v;
              if i=d then continue;
              inc(qsave); inc(val[now.r,now.c,i]);
              with queue[qsave] do
                begin
                  r:=now.r; c:=now.c; dir:=i;
                end;
            end;
      end;
    inc(qtake);
  until qtake>qsave;
  writeln(-1);
end.
