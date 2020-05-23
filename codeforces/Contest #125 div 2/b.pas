var
  x1,y1,x2,y2,r1,r2,rr1,rr2:extended;
  ans:longint;

function distance(x1,y1,x2,y2:extended):extended;
  begin
    exit(sqrt(sqr(x1-x2)+sqr(y1-y2)));
  end;
  
function inside(x1,y1,r1,x2,y2,r2:extended):boolean;
  begin
    exit(distance(x1,y1,x2,y2)+r1<=r2);
  end;

function outside(x1,y1,r1,x2,y2,r2:extended):boolean;
  begin
    exit((distance(x1,y1,x2,y2)>=r1+r2) or inside(x2,y2,r2,x1,y1,r1));
  end;

begin
  readln(x1,y1,r1,rr1);
  readln(x2,y2,r2,rr2);
  if outside(x1,y1,r1,x2,y2,rr2) or inside(x1,y1,r1,x2,y2,r2) then inc(ans);
  if outside(x1,y1,rr1,x2,y2,rr2) or inside(x1,y1,rr1,x2,y2,r2) then inc(ans);
  if outside(x2,y2,r2,x1,y1,rr1) or inside(x2,y2,r2,x1,y1,r1) then inc(ans);
  if outside(x2,y2,rr2,x1,y1,rr1) or inside(x2,y2,rr2,x1,y1,r1) then inc(ans);
  writeln(ans);
end.
