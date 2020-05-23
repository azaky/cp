var
  n,i,j:longint;
  x,y,ans:real;
  x1,x2,y1,y2:array[1..100] of integer;
  connected:array[1..100,1..100] of boolean;
  xint,yint:array[1..100,1..100] of real;
  path:array[0..100,1..100] of real;

function d(xa,ya,xb,yb:real):real;
  begin
    d:=sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
  end;

procedure dijkstra(l,k:integer; dis,x0,y0:real);
  var
    i:integer;

  begin
    writeln(l,',',k,' ',dis:0:2,' ',x0:0:2,',',y0:0:2);
    if k=n then
      if (ans<0) or (ans>dis+d(x0,y0,x2[n],y2[n])) then ans:=dis+d(x0,y0,x2[n],y2[n])
        else
      else if l<k then
        if (path[l,k]<0) or (path[l,k]>dis) then
          begin
            path[l,k]:=dis;
            for i:=1 to n do
              if connected[i,k] and (i<>l) then dijkstra(k,i,(dis+d(x0,y0,xint[i,k],yint[i,k])),xint[i,k],yint[i,k]);
          end
        else
      else if (path[k,l]<0) or (path[k,l]>dis) then
        begin
          path[k,l]:=dis;
          for i:=1 to n do
            if connected[i,k] and (i<>l) then dijkstra(k,i,(dis+d(x0,y0,xint[i,k],yint[i,k])),xint[i,k],yint[i,k]);
        end;
  end;

begin
  readln(n);
  for i:=1 to n do readln(x1[i],y1[i],x2[i],y2[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if (y1[i]-y2[i])*(x1[j]-x2[j])<>(x1[i]-x2[i])*(y1[j]-y2[j]) then
        begin
          x:=((x1[j]-x2[j])*(x1[i]*y2[i]-x2[i]*y1[i])-(x1[i]-x2[i])*(x1[j]*y2[j]-x2[j]*y1[j]))/((y1[j]-y2[j])*(x1[i]-x2[i])-(y1[i]-y2[i])*(x1[j]-x2[j]));
          y:=((y1[j]-y2[j])*(y1[i]*x2[i]-y2[i]*x1[i])-(y1[i]-y2[i])*(y1[j]*x2[j]-y2[j]*x1[j]))/((x1[j]-x2[j])*(y1[i]-y2[i])-(x1[i]-x2[i])*(y1[j]-y2[j]));
          if ((x1[i]-x)*(x-x2[i])>=0) and ((x1[j]-x)*(x-x2[j])>=0) and ((y1[i]-y)*(y-y2[i])>=0) and ((y1[j]-y)*(y-y2[j])>=0) then
            begin
              connected[i,j]:=true;
              xint[i,j]:=x;
              yint[i,j]:=y;
              connected[j,i]:=true;
              xint[j,i]:=x;
              yint[j,i]:=y;
            end;
        end;
  for i:=0 to n do
    for j:=1 to n do path[i,j]:=-1.00;
  ans:=-1.00;
  dijkstra(0,1,0.00,x1[1],y1[1]);
{
  for i:=1 to n do
    begin
      for j:=1 to n do write(xint[i,j]:0:2,';',yint[i,j]:0:2,'  ');
      writeln;
    end;
  for i:=1 to n do
    begin
      for j:=1 to n do write(path[i,j]:0:2,'  ');
      writeln;
    end;
}
  writeln(ans:0:2);
end.
