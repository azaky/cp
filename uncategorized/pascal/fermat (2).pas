const
  maxp = 25;
  p:array[1..maxp] of int64 = (2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97);
  maxtest = 1000000;

var
  i:longint;
  t:int64;

function fermat(n:int64):boolean;
  var
    i:longint;
  
  function power(a,b,c:int64):int64;
    var
      temp:int64;
    
    begin
      if b=0 then exit(1);
      temp:=power(a,b div 2,c);
      temp:=(temp*temp) mod c;
      if b mod 2=1 then temp:=(temp*a) mod c;
      exit(temp);
    end;
  
  begin
    if n=1 then exit(false);
    for i:=1 to maxp do
      if (power(p[i],n,n)-p[i]) mod n<>0 then exit(false);
    //probably true
    exit(true);
  end;

function prime(n:int64):boolean;
  var
    i:longint;
  
  begin
    if n=1 then exit(false);
    for i:=2 to trunc(sqrt(n)) do
      if n mod i=0 then exit(false);
    exit(true);
  end;

begin
  for i:=1 to maxtest do
    begin
      t:=i;
      if fermat(t) then writeln(t);
      //if fermat(t) xor prime(t) then writeln('ERROR ',t);
    end;
end.

