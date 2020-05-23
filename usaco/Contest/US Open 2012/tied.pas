{
ID: a_zaky01
PROG: tied
LANG: PASCAL
}
type
  point=record
    x,y:extended;
  end;

Var
  m,n,i,j,nc,ns,k,ans:longint;
  tx,y:extended;
  b,temp:point;
  c,stack:array[0..11111] of longint;
  mark:array[0..11] of longint;
  p:array[0..11] of point;
  r:array[0..11111] of point;

Begin
    Assign(input, 'tied.in'); Reset(input);
    Assign(output, 'tied.out'); Rewrite(output);
  readln(n,m,b.x,b.y);
  for i:=1 to n do readln(p[i].x,p[i].y);
  for i:=1 to n-1 do
    for j:=n downto i+1 do
      if p[j].y<p[j-1].y then
        begin
          temp:=p[j]; p[j]:=p[j-1]; p[j-1]:=temp;
        end;
  tx:=p[1].x;
  p[0].x:=tx; p[0].y:=-11111;
  p[n+1].x:=tx; p[n+1].y:=11111;
  for i:=1 to m+1 do
    begin
      readln(r[i].x,r[i].y);
      //if r[i].x=tx then r[i].x:=r[i].x+1;
    end;
  i:=1;
  while i<=m do
    begin
      if (r[i].x-tx)*(r[i+1].x-tx)<0 then
        begin
          y:=r[i].y+(tx-r[i].x)*(r[i].y-r[i+1].y)/(r[i].x-r[i+1].x);
          for j:=0 to n do
            if (y-p[j].y)*(y-p[j+1].y)<0 then break;
          inc(nc); c[nc]:=j;
        end;
      if r[i].x<>tx then
        begin
          inc(i); continue;
        end;
      for j:=0 to n do
        if (r[i].y-p[j].y)*(r[i].y-p[j+1].y)<0 then break;
      temp:=r[i-1];
      while r[i].x=tx do inc(i);
      if (temp.x-tx)*(r[i].x-tx)>0 then continue;
      inc(nc); c[nc]:=j;
    end;
  //writeln(nc);
  //for i:=1 to nc do write(c[i]:5);writeln;
  ans:=n;
  for k:=1 to (1 shl n)-1 do
    begin
      for i:=1 to n do
        if (k and (1 shl (i-1)))>0 then mark[i]:=mark[i-1]+1 else mark[i]:=mark[i-1];
      ns:=0; stack[0]:=-10;
      for i:=1 to nc do
        if mark[c[nc]]=stack[ns] then dec(ns)
          else
            begin
              inc(ns); stack[ns]:=mark[c[nc]];
            end;
      if (ns=0) and (mark[n]<ans) then ans:=mark[n];
    end;
  writeln(ans);
    Close(input); Close(output);
End.
