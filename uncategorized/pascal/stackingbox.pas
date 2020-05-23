{
Mary Anne has N (1<=N<=1000) boxes, and she is going to make a stack of boxes.
Each box has its own characteristic: i-th box has height of Hi cm
(1<=Hi<=1000), and it takes Pi (0<=Pi<=1000000) energy for Mary to lift it up,
per centimeter. Calculate the minimum possible energy to make a stack of all
boxes.
}

var
  n,i,j,best:longint;
  energy,total:int64;
  h,p:array[0..1000] of int64;
  used:array[1..1000] of boolean;

begin
  readln(n);
  for i:=1 to n do readln(h[i],p[i]);
  total:=0;
  energy:=0;
  for i:=1 to n do inc(total,h[i]);
  for i:=1 to n do
    begin
      best:=0;
      for j:=1 to n do
        if not used[j] then
          if (best=0) or ((total-h[j])*p[j]<(total-h[best])*p[best]) then best:=j;
      dec(total,h[best]);
      inc(energy,total*p[best]);
      used[best]:=true;
    end;
  writeln(energy);
end.
