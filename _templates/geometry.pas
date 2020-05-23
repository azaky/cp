uses math;

type
  point=record
    x,y:extended;
  end;
  segment=record
    p1,p2:point;
  end;

const
  ep = 1e-11; eps = ep;
  inf = 1.1e4932;
  o : point = (x:0; y:0);

operator + (p1,p2:point) res:point;
  begin
    res.x := p1.x + p2.x;
    res.y := p1.y + p2.y;
  end;

operator - (p1,p2:point) res:point;
  begin
    res.x := p1.x - p2.x;
    res.y := p1.y - p2.y;
  end;

operator * (scalar:extended; p:point) res:point;
  begin
    res.x := scalar*p.x;
    res.y := scalar*p.y;
  end;
operator * (p:point; scalar:extended) res:point;
  begin
    res.x := scalar*p.x;
    res.y := scalar*p.y;
  end;

operator / (p:point; scalar:extended) res:point;
  begin
    res.x := p.x/scalar;
    res.y := p.y/scalar;
  end;

operator = (p1,p2:point) res:boolean;
  begin
    res := (abs(p1.x-p2.x)<ep) and (abs(p1.y-p2.y)<ep);
  end;

operator < (p1,p2:point) res:boolean;
  begin
    res := (p1.x < p2.x) or ((p1.x = p2.x) and (p1.y < p2.y));
  end;

operator > (p1,p2:point) res:boolean;
  begin
    res := (p1.x > p2.x) or ((p1.x = p2.x) and (p1.y > p2.y));
  end;

//returns the distance between two points
function distance(p1,p2:point):extended;
  begin
    exit(sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y)));
  end;

//returns the angle betweeen three points
function angle(p,o,q:point):extended;
  var
    c,pp,oo,qq:extended;
  
  begin
    pp:=distance(o,q); oo:=distance(p,q); qq:=distance(p,o);
    c := (sqr(pp)+sqr(qq)-sqr(oo))/(2*pp*qq);
    if c < -1 then exit(arccos(-1));
    if c >  1 then exit(arccos(1));
    exit(arccos(c));
  end;

//returns the distance between a point and a segment
function distance(p:point; l:segment):extended;
  var
    a,b,c:extended;
    
  begin
    if angle(p,l.p1,l.p2) > Pi/2 then exit(distance(p,l.p1));
    if angle(p,l.p2,l.p1) > Pi/2 then exit(distance(p,l.p2));
    a := l.p1.y-l.p2.y;
    b := l.p2.x-l.p1.x;
    c := l.p1.x*l.p2.y-l.p2.x*l.p1.y;
    exit(abs(a*p.x+b*p.y+c)/sqrt(sqr(a)+sqr(b)));
  end;

//returns the length of a segment
function length(s:segment):extended;
  begin
    exit(distance(s.p1,s.p2));
  end;

//rotates point p about a point o by an angle Theta
function rotate(p,o:point; Theta:extended):point;
  begin
    rotate.x := o.x + (p.x-o.x)*cos(Theta) - (p.y-o.y)*sin(Theta);
    rotate.y := o.y + (p.x-o.x)*sin(Theta) + (p.y-o.y)*cos(Theta);
  end;

//dilates a point p about a point o by a factor
function Dilate(p,o:point; factor:extended):point;
  begin
    exit(o+factor*(p-o));
  end;

//returns the z-component of cross product of two vectors
//if the z-component is positive, then these two vectors form a left turn
//otherwise a right turn
function cross(p1,p2:point):extended;
  begin
    exit(p1.x*p2.y-p1.y*p2.x);
  end;

//returns a boolean value that shows three points form a right turn or not
function right(p1,p2,p3:point):boolean;
  begin
    exit(cross(p2-p1,p3-p2)<=0);
  end;

//returns a boolean value that shows two points lies on the same side of a line or not
function sameside(p1,p2:point; s:segment):boolean;
  var
    z1,z2:extended;

  begin
    z1:=cross(s.p2-s.p1,p1-s.p1);
    z2:=cross(s.p2-s.p1,p2-s.p1);
    exit((z1*z2>=0) or (abs(z1)<ep) or (abs(z2)<ep));
  end;

//returns a boolean value that shows a point lies on a line or not
function online(p:point; l:segment):boolean;
  begin
    with l do exit(abs((p1.y-p.y)*(p2.x-p.x)-(p2.y-p.y)*(p1.x-p.x))<ep);
  end;

//returns a boolean value that shows a point lies on a segment or not
function onsegment(p:point; s:segment):boolean;
  begin
    exit(abs(distance(p,s.p1)+distance(p,s.p2)-distance(s.p1,s.p2))<ep);
  end;

//returns a boolean value that shows two segments intersect each other or not
function intersect(s1,s2:segment):boolean;
  begin
    exit(not sameside(s1.p1,s1.p2,s2) and not sameside(s2.p1,s2.p2,s1));
  end;

//returns the intersection point of two lines
//if both of them are paralel, then it returns the point of infinity
function intersectpoint(s1,s2:segment):point;
  var
    a1,a2,b1,b2,c1,c2,i:extended;

  begin
    if (s1.p1.y-s1.p2.y)*(s2.p1.x-s2.p2.x)=(s2.p1.y-s2.p2.y)*(s1.p1.x-s1.p2.x) then
      with intersectpoint do
        begin
          x:=inf;
          y:=inf;
        end
    else
      begin
        a1:=s1.p2.x-s1.p1.x;
        b1:=s2.p1.x-s2.p2.x;
        c1:=s2.p1.x-s1.p1.x;
        a2:=s1.p2.y-s1.p1.y;
        b2:=s2.p1.y-s2.p2.y;
        c2:=s2.p1.y-s1.p1.y;
        i:=(c1*b2-c2*b1)/(a1*b2-a2*b1);
        with intersectpoint do
          begin
            x:=s1.p1.x+a1*i;
            y:=s1.p1.y+a2*i;
          end;
      end;
  end;

//below is the sample algorithm that uses computational geometry
//find the convex hull of a given set of points

var
  n,i,nhull:longint;
  mid,c,res:point;
  temp:segment;
  stat:string;
  p:array[1..10000] of point;
  hull:array[1..10000] of longint;

procedure sort(l,r:longint);
  var
    i,j:longint;
    mid,temp:point;
  
  begin
    i:=l; j:=r; mid:=p[(l+r) div 2];
    repeat
      while p[i]<mid do inc(i);
      while p[j]>mid do dec(j);
      if i>j then break;
      temp:=p[i]; p[i]:=p[j]; p[j]:=temp;
      inc(i); dec(j);
    until false;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  readln(n);
  for i:=1 to n do readln(p[i].x,p[i].y);
  sort(1,n);
  nhull:=2; hull[1]:=1; hull[2]:=2;
  for i:=3 to n do
    begin
      while (nhull>1) and right(p[hull[nhull-1]],p[hull[nhull]],p[i]) do dec(nhull);
      inc(nhull); hull[nhull]:=i;
    end;
  for i:=n-1 downto 1 do
    begin
      while (nhull>1) and right(p[hull[nhull-1]],p[hull[nhull]],p[i]) do dec(nhull);
      inc(nhull); hull[nhull]:=i;
    end;
  dec(nhull);
  for i:=1 to nhull do
    with p[hull[i]] do writeln(x:0:2,' ',y:0:2);
  with mid do
    begin
      x:=0; y:=0;
    end;
  for i:=1 to nhull do mid := mid + p[hull[i]]/nhull;
  
  readln(c.x,c.y);
  stat:='inside';
  for i:=1 to nhull-1 do
    begin
      temp.p1:=p[hull[i]];
      temp.p2:=p[hull[i+1]];
      if not sameside(mid,c,temp) then stat:='outside'
        else if onsegment(c,temp) then stat:='coincide';
    end;
  temp.p1:=p[hull[1]];
  temp.p2:=p[hull[nhull]];
  if not sameside(mid,c,temp) then stat:='outside'
    else if onsegment(c,temp) then stat:='coincide';
  writeln(stat);
end.

