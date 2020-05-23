type
  point=record
          x,y:longint;
        end;
  arr=array[1..6] of longint;

var
  n,i,i1,i2,i3,i4,i5,i6,j1,j2,j3,tu1,tu2,tl1,tl2,count:longint;
  convex,up,low:boolean;
  p:array[1..15] of point;
  q:array[1..6] of point;
  
procedure sort(l,r:longint);
  var
    i,j,m:longint;
    temp:point;

  begin
    i:=l;
    j:=r;
    m:=p[(l+r) div 2].x;
    repeat
      while p[i].x<m do inc(i);
      while p[j].x>m do dec(j);
      if i<=j then
        begin
          if i<j then
            begin
              temp:=p[i];
              p[i]:=p[j];
              p[j]:=temp;
            end;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

function grad(p1,p2:point):real;
  begin
    if p1.x=p2.x then
      if p1.y<p2.y then grad:=999999.999999
        else grad:=-999999.999999
      else grad:=(p1.y-p2.y)/(p1.x-p2.x);
  end;

begin
  readln(n);
  for i:=1 to n do readln(p[i].x,p[i].y);
  sort(1,n);
  count:=0;
  for i1:=1 to n-5 do
    for i2:=i1+1 to n-4 do
      for i3:=i2+1 to n-3 do
        for i4:=i3+1 to n-2 do
          for i5:=i4+1 to n-1 do
            for i6:=i5+1 to n do
              begin
                q[1]:=p[i1];
                q[2]:=p[i2];
                q[3]:=p[i3];
                q[4]:=p[i4];
                q[5]:=p[i5];
                q[6]:=p[i6];
                convex:=true;
                for j1:=1 to 4 do
                  for j2:=j1+1 to 5 do 
                    for j3:=j2+1 to 6 do
                      if (q[j1].y-q[j2].y)*(q[j2].x-q[j3].x)=(q[j2].y-q[j3].y)*(q[j1].x-q[j2].x) then convex:=false;
                if convex then
                  begin
                    low:=false;
                    up:=false;
                    for i:=2 to 5 do
                      if convex then
                        if grad(q[1],q[6])<grad(q[1],q[i]) then
                          if not up then
                            begin
                              tu1:=1;
                              tu2:=i;
                              up:=true;
                            end
                          else if grad(q[tu1],q[tu2])>grad(q[tu2],q[i]) then
                            begin
                              tu1:=tu2;
                              tu2:=i;
                            end
                          else convex:=false
                        else if not low then
                          begin
                            tl1:=1;
                            tl2:=i;
                            low:=true;
                          end
                        else if grad(q[tl1],q[tl2])<grad(q[tl2],q[i]) then
                          begin
                            tl1:=tl2;
                            tl2:=i;
                          end
                        else convex:=false;
                      if convex then
                        begin
                          if low then
                            if grad(q[tl1],q[tl2])>grad(q[tl2],q[6]) then convex:=false;
                          if up then
                            if grad(q[tu1],q[tu2])<grad(q[tu2],q[6]) then convex:=false;
                        end;
                      if convex then inc(count);
                  end;
              end;
  writeln(count);
end.
