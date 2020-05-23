const
  cin = 'jalan.txt';
  maxn = 10;
  maxm = 10;
  maxc = 10;
  maxt = 10;

var
  t,i,n,m,x,y,k:longint;
  con:array[1..maxn,1..maxn] of boolean;
  
begin
  assign(output,cin);
  rewrite(output);
  
  randomize;
  t:=maxt;
  writeln(t);
  for k:=1 to t do
    begin
      n:=random(maxn)+1;
      m:=random((n*(n-1)) div 2)+1;
      if m>maxm then m:=random(maxm)+1;
      writeln(n,' ',m);
      writeln;
      for i:=1 to n do
        begin
          x:=random(maxc);
          y:=random(maxc);
          writeln(x,' ',y);
        end;
      writeln;
      fillchar(con,sizeof(con),false);
      for i:=1 to m do
        begin
          repeat
            x:=random(n)+1;
            y:=random(n)+1;
          until not con[x,y] and (x<>y);
          con[x,y]:=true; con[y,x]:=true;
          writeln(x,' ',y);
        end;
      writeln;
      writeln;
    end;
  
  close(output);
end.
