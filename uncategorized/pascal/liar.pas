const
  max=100000;
  dom=1000003;

var
  t,kasus,n,r,k,i,m:longint;
  ans:int64;
  arr:array[1..max] of boolean;
  prime,iprime:array[1..max] of longint;

procedure sieve;
  var
    i,p,k:longint;

  begin
    arr[1]:=true;
    p:=2;
    while p<=trunc(sqrt(max)) do
      begin
        while arr[p] do inc(p);
        for k:=2 to max div p do arr[p*k]:=true;
        inc(p);
      end;
    k:=0;
    iprime[1]:=0;
    for i:=2 to max do
      if arr[i] then iprime[i]:=iprime[i-1]
        else
          begin
            inc(k);
            prime[k]:=i;
            iprime[i]:=iprime[i-1]+1;
          end;
  end;

function power(a,b:longint):int64;
  var
    temp:int64;

  begin
    if b=0 then power:=1
      else
        begin
          temp:=power(a,b div 2);
          if b mod 2=0 then power:=(temp*temp) mod dom
            else power:=(temp*temp*a) mod dom;
        end;
  end;

function deg(a,p:longint):longint;
  var
    temp:longint;

  begin
    temp:=a;
    deg:=0;
    while temp>0 do
      begin
        temp:=temp div p;
        inc(deg,temp);
      end;
  end;

begin
  sieve;
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n,r,k);
      ans:=power(2*n-1,r-k);
      for i:=1 to iprime[r] do
        begin
          m:=deg(r,prime[i])-(deg(k,prime[i])+deg(r-k,prime[i]));
          ans:=(ans*power(prime[i],m)) mod dom;
        end;
      writeln(ans);
    end;
end.
