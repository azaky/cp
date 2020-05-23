var
  n,i,j,k,add,imax,temp,di:longint;
  best,price:extended;
  h:array[1..50] of longint;
  d:array[1..50] of extended;
  stat:array[1..50] of boolean;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(h[i],di);
      d[i]:=(100-di)/100;
    end;
  readln(price);
  add:=0;
  for i:=1 to n do
    begin
      k:=0;
      best:=price+add;
      for j:=1 to n do
        if not stat[j] then
          if (price*d[j]+h[j]+add<best) then
            begin
              best:=price*d[j]+h[j]+add;
              k:=j;
            end;
      if k<>0 then
        begin
          stat[k]:=true;
          price:=price*d[k];
          inc(add,h[k]);
        end;
    end;
{
    for i:=n downto 1 do
      if not stat[i] then
        if (best*(100-d[i])/100)+h[i]<best then
          begin
            best:=best*(100-d[i])/100;
            inc(add,h[i]);
            stat[i]:=true;
          end;
  until temp2=best+add;
}
  writeln((price+add):0:3);
end.
