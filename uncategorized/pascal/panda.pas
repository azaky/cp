const
  ep = 1e-5;
  inf = 1e50;

type
  point=record
    x,y:extended;
  end;
  segment=record
    p1,p2:point;
  end;

var
  t1,kasus,n,i,j,size:longint;
  best,curr,ca,cb:extended;
  valid:boolean;
  w,t,s:array[1..300] of longint;
  seg:array[1..300] of segment;
  temp:point;
  p:array[1..90305] of point;

{find the intersection point of two lines}
function intersectpoint(s1,s2:segment):point;
  var
    a1,a2,b1,b2,c1,c2,i:extended;

  begin
    if abs((s1.p1.y-s1.p2.y)*(s2.p1.x-s2.p2.x)-(s2.p1.y-s2.p2.y)*(s1.p1.x-s1.p2.x))<ep then
      with intersectpoint do
        begin
          x:=-inf;
          y:=-inf;
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
        //writeln(a1:0:2,' ',b1:0:2,' ',c1:0:2,' ',a2:0:2,' ',b2:0:2,' ',c2:0:2,' ',i:0:2);
        with intersectpoint do
          begin
            x:=s1.p1.x+a1*i;
            y:=s1.p1.y+a2*i;
          end;
      end;
  end;

begin
  readln(t1);
  for kasus:=1 to t1 do
    begin
      readln(n);
      for i:=1 to n do read(w[i]);
      for i:=1 to n do read(t[i]);
      for i:=1 to n do read(s[i]);
      readln(ca,cb);
      
      size:=0;
      
      for i:=1 to n do
        with seg[i] do
          begin
            p1.x:=0; p1.y:=w[i]/s[i];
            p2.x:=w[i]/t[i]; p2.y:=0;
            
            valid:=true;
            for j:=1 to i-1 do
              if (seg[i].p1.y<seg[j].p1.y) or (seg[i].p2.x<seg[j].p2.x) then
                begin
                  valid:=false;
                  break;
                end;
            if not valid then continue;
            
            inc(size); p[size]:=p1;
            inc(size); p[size]:=p2;
          end;
      
      for i:=1 to n-1 do
        for j:=i+1 to n do
          begin
            if (seg[i].p2.x-seg[j].p2.x)*(seg[i].p1.y-seg[j].p1.y)>=0 then continue;
            temp:=intersectpoint(seg[i],seg[j]);
            if (temp.x>=0) and (temp.y>=0) then
              begin
                inc(size);
                p[size]:=temp;
              end;
          end;
      
      best:=inf;
      for i:=1 to size do
        begin
          valid:=true;
          for j:=1 to n do
            if (p[i].x*t[j]+p[i].y*s[j]<w[j]) then
              begin
                valid:=false;
                break;
              end;
          if not valid then continue;
          
          //writeln('found!');
          curr:=ca*p[i].x+cb*p[i].y;
          if curr<best then best:=curr;
        end;
      
      writeln(best:0:2);
      
    end;
end.

