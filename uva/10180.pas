uses math;

type
  point = record
    x,y: extended; //(x,y)
  end;
  segment = record
    p1,p2: point; //segment with p1 and p2 as endpoints
  end;

function distance(a,b:point):extended;
  begin
    exit(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
  end;

function length(s:segment):extended;
  begin
    exit(sqrt(sqr(s.p1.x-s.p2.x)+sqr(s.p1.y-s.p2.y)));
  end;

function distance(p:point; l:segment):extended;
  var
    a,b,c:extended;
    
  begin
    a := l.p1.y-l.p2.y;
    b := l.p2.x-l.p1.x;
    c := l.p1.x*l.p2.y-l.p2.x*l.p1.y;
    exit(abs(a*p.x+b*p.y+c)/sqrt(sqr(a)+sqr(b)));
  end;

function rotate(p,o:point; angle:extended):point;
  begin
    rotate.x := o.x + (p.x-o.x)*cos(angle) - (p.y-o.y)*sin(angle);
    rotate.y := o.y + (p.x-o.x)*sin(angle) + (p.y-o.y)*cos(angle);
  end;

function angle(p,o,q:point):extended;
  var
    pp,oo,qq:extended;
  
  begin
    pp:=distance(o,q); oo:=distance(p,q); qq:=distance(p,o);
    exit(arccos((sqr(pp)+sqr(qq)-sqr(oo))/(2*pp*qq))); //determining the angle using the Law of Cosine
  end;

var
  n,tc:longint;
  o,h,s,t,a1,a2,b1,b2:point;
  rope:segment;
  r,d,Gamma,dis1,dis2:extended;

function outside(l:segment):boolean;
  begin
    if distance(o,l)>=r then exit(true);
    exit(not((angle(o,l.p1,l.p2)<Pi/2) and (angle(o,l.p2,l.p1)<Pi/2)));
  end;

begin
  readln(n); o.x:=0; o.y:=0;
  for tc:=1 to n do
    begin
      readln(h.x,h.y,s.x,s.y,r);
      rope.p1 := h; rope.p2 := s;
      //check if straight rope is possible
      if (h.x=s.x) and (h.y=s.y) then
        begin
          writeln(length(rope):0:3); continue;
        end;
      if outside(rope) then
        begin
          writeln(length(rope):0:3); continue;
        end;
      d := distance(h,o);
      t.x := h.x*r/d; t.y := h.y*r/d;
      Gamma := arccos(r/d);
      a1:=rotate(t,o,Gamma); a2:=rotate(t,o,-Gamma);
      d := distance(s,o);
      t.x := s.x*r/d; t.y := s.y*r/d;
      Gamma := arccos(r/d);
      b1:=rotate(t,o,-Gamma); b2:=rotate(t,o,Gamma);
      
      dis1 := distance(h,a1) + r*angle(a1,o,b1) + distance(b1,s);
      dis2 := distance(h,a2) + r*angle(a2,o,b2) + distance(b2,s);
      writeln(min(dis1,dis2):0:3);
    end;
end.
