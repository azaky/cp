var
  n,p,temp,count:longint;
  stat:boolean;
  pi,q:array[1..10000000] of longint;

function gcd(a,b:longint):longint;
  begin
    if a=0 then gcd:=b
      else gcd:=gcd(b mod a,a);
  end;

function phi(n:longint):longint;
  var
    i:longint;

  begin
    phi:=0;
    if n=1 then phi:=1
      else for i:=1 to n-1 do
        if gcd(i,n)=1 then inc(phi);
  end;

procedure factorize(n:longint);
  var
    i,j:longint;

  begin
    i:=1;
    p:=2;
    while n<>1 do
      begin
        while n mod p <> 0 do
          begin
            inc(p);
            inc(i);
          end;
        n:=n div p;
        pi[i]:=p;
        inc(q[i]);
      end;
    for j:=i downto 1 do if q[j]<>0 then inc(count);
  end;

begin
  readln(n);
  count:=0;
  if (n=2) or (n=4) then stat:=true
    else
      begin
        temp:=n;
        factorize(temp);
        if count=1 then
          if n mod 2 = 0 then stat:=false
            else stat:=true
          else if count=2 then
            if (n mod 2 = 0) and (n mod 4 <> 0) then stat:=true
              else stat:=false
          else stat:=false;
      end;
  if stat then writeln(phi(phi(n))) else writeln('0');
end.
