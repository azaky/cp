const
  ep = 1e-10;
  inf = 1e50;

type
  point=record
    x,y:extended;
  end;
  segment=record
    p1,p2:point;
  end;

var
  n,i,nhull:longint;
  mid,c:point;
  temp:segment;
  stat:string;
  p:array[1..10000] of point;
  hull:array[1..10000] of longint;

//returns the distance between two points
function distance(p1,p2:point):extended;
  begin
    exit(sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y)));
  end;

//returns the length of a segment
function length(s:segment):extended;
  begin
    exit(distance(s.p1,s.p2));
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
  var
    temp1,temp2:point;
  
  begin
    with temp1 do
      begin
        x:=p2.x-p1.x;
        y:=p2.y-p1.y;
      end;
    with temp2 do
      begin
        x:=p3.x-p2.x;
        y:=p3.y-p2.y;
      end;
    exit(cross(temp1,temp2)<=0);
  end;

//returns a boolean value that shows two points lies on the same side of a line or not
function sameside(p1,p2:point; s:segment):boolean;
  var
    temp,temp1,temp2:point;
    z1,z2:extended;

  begin
    with temp do
      begin
        x:=s.p2.x-s.p1.x;
        y:=s.p2.y-s.p1.y;
      end;
    with temp1 do
      begin
        x:=p1.x-s.p1.x;
        y:=p1.y-s.p1.y;
      end;
    with temp2 do
      begin
        x:=p2.x-s.p1.x;
        y:=p2.y-s.p1.y;
      end;
    z1:=cross(temp,temp1);
    z2:=cross(temp,temp2);
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

procedure sort(l,r:longint);
  var
    i,j:longint;
    mid,temp:point;
  
  begin
    i:=l; j:=r; mid:=p[(l+r) div 2];
    repeat
      while (p[i].x<mid.x) or ((p[i].x=mid.x) and (p[i].y<mid.y)) do inc(i);
      while (p[j].x>mid.x) or ((p[j].x=mid.x) and (p[j].y>mid.y)) do dec(j);
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
  for i:=1 to nhull do
    begin
      mid.x:=mid.x+p[hull[i]].x/nhull;
      mid.y:=mid.y+p[hull[i]].y/nhull;
    end;
  
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

