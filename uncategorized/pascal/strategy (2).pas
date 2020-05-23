var
  t,kasus,n,i,j,best,mid:integer;
  w:array[1..3,1..12] of integer;

procedure code(a,b,c,time,k:integer);
  var
    prob:integer;
    
  begin
    if (a>mid) or (b>mid) or (b>mid) or (best=n) then exit;
    prob:=a+b+c;
    if prob>best then
      if (a<=(prob+1) div 2) and (b<=(prob+1) div 2) and (c<=(prob+1) div 2) then best:=prob;
    if (k=n) or (prob+n-k<best) then exit;
    inc(k); code(a,b,c,time,k);
    if time+w[1,k]<=280 then code(a+1,b,c,time+w[1,k],k);
    if time+w[2,k]<=280 then code(a,b+1,c,time+w[2,k],k);
    if time+w[3,k]<=280 then code(a,b,c+1,time+w[3,k],k);
  end;

begin
{
  assign(input,'strategy.txt'); reset(input);
  assign(output,'strategy.out'); rewrite(output);
}
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      for i:=1 to 3 do
        for j:=1 to n do read(w[i][j]);
      best:=0; mid:=(n+1) div 2;
      code(0,0,0,0,0);
      writeln(best);
    end;
{
  close(input);
  close(output);
}
end.

