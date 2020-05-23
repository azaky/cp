const
  maxn = 1000000000;
  maxp = trunc(sqrt(maxn));

var
  n,i,j,nprime,m,tc,kasus:longint;
  suspect:boolean;
  mark:array[0..2309] of boolean;
  prime:array[1..maxp] of boolean;
  p:array[1..maxp] of longint;

begin
  //sieve
  fillchar(prime,sizeof(prime),true); prime[1]:=false;
  for i:=2 to trunc(sqrt(maxp)) do
    if prime[i] then
      for j:=i to maxp div i do prime[i*j]:=false;
  nprime:=0;
  for i:=2 to maxp do
    if prime[i] then
      begin
        inc(nprime); p[nprime]:=i;
      end;
  //marking
  for i:=0 to 2309 do
    mark[i]:=(i mod 2=0) or (i mod 3=0) or (i mod 5=0) or (i mod 7=0) or (i mod 11=0);
  //working
  readln(tc);
  for kasus:=1 to tc do
    begin
      readln(m,n);
      for i:=m to n do
        begin
          if mark[i mod 2310] and (i>maxp) then continue;
          suspect:=true;
          if i<=maxp then
            if not prime[i] then suspect:=false
              else
          else for j:=1 to nprime do
            begin
              if p[j]*p[j]>i then break;
              if i mod p[j]=0 then
                begin
                  suspect:=false;
                  break;
                end;
            end;
          if suspect then writeln(i);
        end;
      if kasus<tc then writeln;
    end;
end.

