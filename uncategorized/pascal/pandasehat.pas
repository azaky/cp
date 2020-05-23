var
  t,kasus,i,j,k,n,pa,pb:longint;
  w,a,b:array[1..300] of integer;
  x,y,p:real;
  stat:boolean;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      x:=0;
      y:=0;
      for i:=1 to n do read(w[i]);
      for i:=1 to n do
        begin
          read(a[i]);
          if w[i]/a[i]>x then x:=w[i]/a[i];
        end;
      for i:=1 to n do
        begin
          read(b[i]);
          if w[i]/b[i]>y then y:=w[i]/b[i];
        end;
      readln(pa,pb);
      if x*pa<y*pb then p:=x*pa
        else p:=y*pb;
      for i:=1 to n-1 do
        for j:=i+1 to n do
          if (a[i]*b[j]-a[j]*b[i])<>0 then
            begin
              x:=(w[i]*b[j]-w[j]*b[i])/(a[i]*b[j]-a[j]*b[i]);
              y:=(w[i]*a[j]-w[j]*a[i])/(b[i]*a[j]-b[j]*a[i]);
              if (x>=0) and (y>=0) then
                begin
                  stat:=true;
                  for k:=1 to n do
                    if abs(ka[k]*(w[i]*b[j]-w[j]*b[i])-b[k]*(w[i]*a[j]-w[j]*a[i]))<abs(w[k]*(a[i]*b[j]-a[j]*b[i])) then
                      begin
                        stat:=false;
                        break;
                      end;
                  if stat then
                    if x*pa+y*pb<p then p:=x*pa+y*pb;
                end;
            end;
      writeln(p:0:2);
    end;
end.
