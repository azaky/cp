{
ID: a_zaky01
PROG: fence4
LANG: PASCAL
}

const
  ep=0.0000001;

type
  point=record
    x,y:extended;
  end;
  segment=record
    p1,p2:point;
  end;

var
  n,i,j,count:longint;
  pob,t1,t2,temp:point;
  s1,s2:segment;
  leg1,leg2:segment;
  valid,in1,in2:boolean;
  poly:array[1..200] of point;
  seg:array[1..200] of segment;
  seen:array[1..200] of boolean;
  fin,fout:text;

{distance between two points}
function distance(point1,point2:point):extended;
  begin
    distance:=sqrt((point1.x-point2.x)*(point1.x-point2.x)+(point1.y-point2.y)*(point1.y-point2.y));
  end;

{length of a segment}
function length(s:segment):extended;
  begin
    length:=distance(s.p1,s.p2);
  end;

{the z component of cross product of two vectors}
function cross(point1,point2:point):extended;
  begin
    cross:=point1.x*point2.y-point1.y*point2.x;
  end;

{checks whether two points lies on the same side of a line or not}
function sameside(point1,point2:point; s:segment):boolean;
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
        x:=point1.x-s.p1.x;
        y:=point1.y-s.p1.y;
      end;
    with temp2 do
      begin
        x:=point2.x-s.p1.x;
        y:=point2.y-s.p1.y;
      end;
    z1:=cross(temp,temp1);
    z2:=cross(temp,temp2);
    if z1*z2>0 then sameside:=true
      else sameside:=false;
  end;

{checks whether a point lies on a line or not}
function online(p:point; l:segment):boolean;
  begin
    online:=false;
    with l do
      if abs((p1.y-p.y)*(p2.x-p.x)-(p2.y-p.y)*(p1.x-p.x))<ep then online:=true;
  end;

{checks whether a point lies on a segment or not}
function onsegment(p:point; s:segment):boolean;
  begin
    onsegment:=false;
    if online(p,s) then
      if abs(distance(p,s.p1)+distance(p,s.p2)-distance(s.p1,s.p2))<ep then onsegment:=true;
  end;

{check whether two segments intersect each other or not}
function intersect(s1,s2:segment):boolean;
  begin
    intersect:=false;
    if not sameside(s1.p1,s1.p2,s2) and not sameside(s2.p1,s2.p2,s1) then intersect:=true;
    if onsegment(s1.p1,s2) or onsegment(s1.p2,s2) or onsegment(s2.p1,s1) or onsegment(s2.p2,s1) then intersect:=true
      else if online(s1.p1,s2) and online(s1.p2,s2) then intersect:=false;
  end;

{find the intersection point of two lines}
function intersectpoint(s1,s2:segment):point;
  var
    a1,a2,b1,b2,c1,c2,i:extended;

  begin
    if (s1.p1.y-s1.p2.y)*(s2.p1.x-s2.p2.x)=(s2.p1.y-s2.p2.y)*(s1.p1.x-s1.p2.x) then
      with intersectpoint do
        begin
          x:=-50000.0;
          y:=-50000.0;
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

{checks wheter a point lies inside a triangle or not}
function intriangle(p,t1,t2,t3:point):boolean;
  var
    temp:point;
    s1,s2,s3:segment;

  begin
    intriangle:=true;
    with temp do
      begin
        x:=(t1.x+t2.x+t3.x)/3;
        y:=(t1.y+t2.y+t3.y)/3;
      end;
    with s1 do
      begin
        p1:=t2;
        p2:=t3;
      end;
    with s2 do
      begin
        p1:=t1;
        p2:=t3;
      end;
    with s3 do
      begin
        p1:=t1;
        p2:=t2;
      end;
    if not sameside(p,temp,s1) or not sameside(p,temp,s2) or not sameside(p,temp,s3) then intriangle:=false;
  end;

begin
  assign(fin,'fence4.in');
  assign(fout,'fence4.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  readln(fin,pob.x,pob.y);
  for i:=1 to n do
    with poly[i] do readln(fin,x,y);
  for i:=2 to n do
    with seg[i] do
      begin
        p1:=poly[i-1];
        p2:=poly[i];
      end;
  with seg[1] do
    begin
      p1:=poly[n];
      p2:=poly[1];
    end;
  valid:=true;
  for i:=1 to n do
    if online(poly[(i mod n)+1],seg[i]) and (distance(poly[(i mod n)+1],poly[((i-2+n) mod n)+1])<length(seg[i])+length(seg[(i mod n)+1])) then
      begin
        valid:=false;
        break;
      end;
  if valid then
    for i:=1 to n do
      if valid then
        for j:=1 to n do
          if i<>j then
            if ((j<>(i mod n)+1) and (j<>((i-2+n) mod n)+1) and intersect(seg[i],seg[j])) or ((j<>(i mod n)+1) and onsegment(poly[i],seg[j])) then
              begin
                valid:=false;
                break;
              end;
  if not valid then writeln(fout,'NOFENCE')
    else
      begin
        fillchar(seen,sizeof(seen),true);
        count:=n;
        for i:=1 to n do
          begin
            t1:=poly[((i-2+n) mod n)+1];
            t2:=poly[i];
            with leg1 do
              begin
                p1:=pob;
                p2:=t1;
              end;
            with leg2 do
              begin
                p1:=pob;
                p2:=t2;
              end;
            for j:=1 to n do
              if seen[i] then
                if i<>j then
                  begin
                    in1:=intersect(seg[j],leg1);
                    in2:=intersect(seg[j],leg2);
                    if in1 then
                      begin
                        if intriangle(seg[j].p1,pob,t1,t2) then
                          begin
                            leg1.p2:=seg[j].p1;
                            t1:=intersectpoint(leg1,seg[i]);
                            leg1.p2:=t1;
                          end;
                        if intriangle(seg[j].p2,pob,t1,t2) then
                          begin
                            leg1.p2:=seg[j].p2;
                            t1:=intersectpoint(leg1,seg[i]);
                            leg1.p2:=t1;
                          end;
                      end;
                    if in2 then
                      begin
                        if intriangle(seg[j].p1,pob,t1,t2) then
                          begin
                            leg2.p2:=seg[j].p1;
                            t2:=intersectpoint(leg2,seg[i]);
                            leg2.p2:=t2;
                          end;
                        if intriangle(seg[j].p2,pob,t1,t2) then
                          begin
                            leg2.p2:=seg[j].p2;
                            t2:=intersectpoint(leg2,seg[i]);
                            leg2.p2:=t2;
                          end;
                      end;
                    if (in1 and in2) or ((abs(t1.x-t2.x)<ep) and (abs(t1.y-t2.y)<ep)) then
                      begin
                        seen[i]:=false;
                        dec(count);
                        break;
                      end;
                  end;
          end;
        writeln(fout,count);
        for i:=2 to n-1 do
          if seen[i] then writeln(fout,seg[i].p1.x:0:0,' ',seg[i].p1.y:0:0,' ',seg[i].p2.x:0:0,' ',seg[i].p2.y:0:0);
        if seen[1] then writeln(fout,seg[1].p2.x:0:0,' ',seg[1].p2.y:0:0,' ',seg[1].p1.x:0:0,' ',seg[1].p1.y:0:0);
        if seen[n] then writeln(fout,seg[n].p1.x:0:0,' ',seg[n].p1.y:0:0,' ',seg[n].p2.x:0:0,' ',seg[n].p2.y:0:0);
      end;
  close(fin);
  close(fout);
end.
