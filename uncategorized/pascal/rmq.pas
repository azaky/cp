const
  maxn = 1000000;
  maxs = 1001;
  inf = 2000000001;

var
  n,i,s,q,x,y,temp,tmax,tmin,pos:longint;
  a:array[1..maxn] of longint;
  max,min:array[0..maxs] of longint;

begin
  
  assign(input,'text.txt'); reset(input);
  assign(output,'text.out'); rewrite(output);
  
  readln(n,q); writeln(n,' ',q);
  for i:=1 to n do read(a[i]);
  
  s:=trunc(sqrt(n));
  
  temp:=0;
  for i:=1 to n+1 do
    if (i mod s=1) or (i>n) then
      begin
        max[temp]:=tmax; min[temp]:=tmin;
        inc(temp);
        tmax:=a[i]; tmin:=a[i];
      end
    else
      begin
        if a[i]>tmax then tmax:=a[i];
        if a[i]<tmin then tmin:=a[i];
      end;
  
  for i:=1 to q do
    begin
      readln(x,y);
      if x>y then
        begin
          temp:=x;
          x:=y;
          y:=temp;
        end;
      pos:=x;
      tmax:=-inf; tmin:=inf;
      while pos<=y do
        if (pos mod s=1) and (pos+s-1<=y) then
          begin
            temp:=1+(pos div s);
            if max[temp]>tmax then tmax:=max[temp];
            if min[temp]<tmin then tmin:=min[temp];
            pos:=pos+s;
          end
        else
          begin
            if a[pos]>tmax then tmax:=a[pos];
            if a[pos]<tmin then tmin:=a[pos];
            inc(pos);
          end;
      writeln(tmax,' ',tmin);
    end;
  
  close(input);
  close(output);
end.

