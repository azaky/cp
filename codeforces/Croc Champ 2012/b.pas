uses math;

const ep = 1e-9;

type point = record x,y:extended; end;

var
  m,n,i,j,k,t,ans,count:longint;
  f:array[0..300] of point;
  x:extended;
  seen:array[0..1111111] of longint;

begin
  readln(n,m);
  for i:=1 to m do readln(f[i].x,f[i].y);
  for i:=1 to m-1 do
    for j:=i+1 to m do
      begin
        if f[i].y=f[j].y then continue;
        x := f[i].x-f[i].y*(f[i].x-f[j].x)/(f[i].y-f[j].y);
        if abs(x-round(x))<ep then
          begin
            t := round(x); count:=0;
            if (t<=0) or (t>n) then continue;
            for k:=1 to m do
              if abs((f[k].x-f[i].x)*(f[i].y-f[j].y)-(f[k].y-f[i].y)*(f[i].x-f[j].x))<ep then inc(count);
            seen[t]:=max(seen[t],count);
          end;
      end;
  for i:=1 to n do
    if seen[i]=0 then seen[i]:=1;
  //for i:=1 to n do write(seen[i]:5);writeln;
  for i:=1 to n do ans:=ans+seen[i];
  writeln(ans);
end.
