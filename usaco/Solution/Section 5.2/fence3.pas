{
ID: a_zaky01
PROG: fence3
LANG: PASCAL
}

uses
  math;

type
  point=record
    x,y:extended;
  end;

const
  zx : array[1..4] of integer = (1,0,-1,0);
  zy : array[1..4] of integer = (0,1,0,-1);

var
  n,i,acc,next:longint;
  best,move,temp:extended;
  cur:point;
  p1,p2:array[1..150] of point;

function distance(p1,p2:point):extended;
  begin
    distance:=sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
  end;

function wire(p:point; k:integer):extended;
  begin
    if p1[k].x=p2[k].x then
      if (p1[k].y-p.y)*(p2[k].y-p.y)<=0 then exit(abs(p1[k].x-p.x))
        else
      else if (p1[k].x-p.x)*(p2[k].x-p.x)<=0 then exit(abs(p1[k].y-p.y));
    exit(min(distance(p,p1[k]),distance(p,p2[k])));
  end;

function total(p:point):extended;
  var
    i:integer;

  begin
    total:=0.0;
    for i:=1 to n do total:=total+wire(p,i);
  end;

begin

  assign(input,'fence3.in');
  assign(output,'fence3.out');
  reset(input);
  rewrite(output);


  readln(n);
  for i:=1 to n do readln(p1[i].x,p1[i].y,p2[i].x,p2[i].y);
  
  with cur do
    begin
      x:=50; y:=50;
    end;
  best:=total(cur);
  acc:=0;
  move:=11;
  
  while true do
    begin
      if acc=10 then break;
      
      //with cur do writeln(x:0:acc,' ',y:0:acc,' ',best:0:acc);
      
      next:=-1;
      for i:=1 to 4 do
        begin
          with cur do
            begin
              x:=x+move*zx[i];
              y:=y+move*zy[i];
            end;
          temp:=total(cur);
          if temp<best then
            begin
              next:=i;
              best:=temp;
            end;
          with cur do
            begin
              x:=x-move*zx[i];
              y:=y-move*zy[i];
            end;
        end;
      
      if next=-1 then
        begin
          inc(acc);
          move:=move*0.1;
        end
      else with cur do
        begin
          x:=x+move*zx[next];
          y:=y+move*zy[next];
        end;
      
    end;
  
  with cur do writeln(x:0:1,' ',y:0:1,' ',best:0:1);
  

  close(input);
  close(output);

end.
