var
  a,b,c,n,temp,temp2,pola,pstart:int64;
  i,k:longint;
  gr:boolean;
  slot:array[0..9999999] of byte;

function power(a,b,m:int64):int64;
  var
    temp:int64;

  begin
    if b=0 then power:=1
      else
        begin
          temp:=power(a,b div 2,m);
          if b mod 2=0 then power:=(temp*temp) mod m
            else power:=(temp*temp*a) mod m;
        end;
  end;

begin
  readln(a,b,c,n);
  temp:=1;
  k:=0;
  while true do
    begin
      inc(k);
      temp:=(temp*a) mod n;
      inc(slot[temp]);
      if slot[temp]=2 then break;
    end;
  temp2:=temp;
  temp:=1;
  for i:=1 to k do
    begin
      temp:=(temp*a) mod n;
      if temp=temp2 then break;
    end;
  pola:=k-i;
  pstart:=i-1;
  gr:=false;
  temp:=1;
  for i:=1 to c do
    begin
      temp:=temp*b;
      if temp>pstart then
        begin
          gr:=true;
          break;
        end;
    end;
  temp:=power(b,c,pola);
  if temp=0 then temp:=pola;
  if gr then temp:=pstart+pola+((temp-pstart) mod pola);
  writeln(1+power(a,temp,n));
end.
