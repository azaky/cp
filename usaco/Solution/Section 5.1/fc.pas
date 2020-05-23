{
ID: a_zaky01
PROG: fc
LANG: PASCAL
}

uses
  math;

type
  point=record
          x,y:extended;
        end;

label
  closefile;

var
  pi,ans:extended;
  n,i,pos,start:longint;
  mid,temp:point;
  flag:boolean;
  p,hull:array[0..10001] of point;
  angle:array[1..10000] of extended;
  fin,fout:text;

function distance(point1,point2:point):extended;
  begin
    distance:=sqrt((point1.x-point2.x)*(point1.x-point2.x)+(point1.y-point2.y)*(point1.y-point2.y));
  end;

function zcross(point1,point2:point):extended;
  begin
    zcross:=point1.x*point2.y-point1.y*point2.x;
  end;

function sub(point1,point2:point):point;
  begin
    sub.x:=point1.x-point2.x;
    sub.y:=point1.y-point2.y;
  end;

function right(p1,p2,p3:point):boolean;
  var
    v1,v2:point;

  begin
    v1:=sub(p1,p2);
    v2:=sub(p2,p3);
    exit(zcross(v1,v2)<0);
  end;

function atan(y,x:extended):extended;
  begin
    if x=0 then
      if y=0 then exit(0.0)
        else if y>0 then exit(pi/2)
          else exit(3*pi/2);
    atan:=arctan(y/x);
    if atan<0 then atan:=atan+pi;
    if y<0 then atan:=atan+pi;
  end;

procedure sort(l,r:longint);
  var
    i,j:longint;
    mid,temp:extended;
    tempp:point;

  begin
    i:=l;
    j:=r;
    mid:=angle[(l+r) div 2];
    repeat
      while angle[i]<mid do inc(i);
      while angle[j]>mid do dec(j);
      if i<=j then
        begin
          temp:=angle[i];
          angle[i]:=angle[j];
          angle[j]:=temp;
          tempp:=p[i];
          p[i]:=p[j];
          p[j]:=tempp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  pi:=arccos(-1); //I wonder why I cannot put it as a constant value

  assign(fin,'fc.in');
  assign(fout,'fc.out');
  reset(fin);
  rewrite(fout);

  readln(fin,n);
  for i:=1 to n do
    with p[i] do readln(fin,x,y);

  if n=1 then
    begin
      writeln(fout,'0.00');
      goto closefile;
    end;

  with mid do
    begin
      x:=0;
      y:=0;
    end;
  for i:=1 to n do
    begin
      mid.x:=mid.x+(p[i].x/n);
      mid.y:=mid.y+(p[i].y/n);
    end;

  for i:=1 to n do angle[i]:=atan(p[i].y-mid.y,p[i].x-mid.x);
  sort(1,n);
  hull[1]:=p[1];
  hull[2]:=p[2];
  pos:=3;
  for i:=3 to n-1 do
    begin
      while (pos>2) and right(hull[pos-2],hull[pos-1],p[i]) do dec(pos);
      hull[pos]:=p[i];
      inc(pos);
    end;

  temp:=p[n];
  while (pos>2) and right(hull[pos-2],hull[pos-1],temp) do dec(pos);

  start:=1;
  repeat
    flag:=false;
    if (pos-start>=2) and right(hull[pos-1],temp,hull[start]) then
      begin
        temp:=hull[pos-1];
        dec(pos);
        flag:=true;
      end;
    if (pos-start>=2) and right(temp,hull[start],hull[start+1]) then
      begin
        inc(start);
        flag:=true;
      end;
  until not flag;
  hull[pos]:=temp;

  ans:=distance(hull[start],hull[pos]);
  for i:=start to pos-1 do ans:=ans+distance(hull[i],hull[i+1]);
  writeln(fout,ans:0:2);

  closefile:
  close(fin);
  close(fout);
end.
