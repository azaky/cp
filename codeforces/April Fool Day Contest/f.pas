const
  maxn = 1000000;

var
  n,i,j,p:longint;
  prime:array[0..maxn] of boolean;

function reverse(a:longint):longint;
  var
    t:longint;
  
  begin
    t:=0;
    while a>0 do begin t:=10*t+(a mod 10); a:=a div 10; end;
    exit(t);
  end;

begin
  readln(n);
  //sieve
  fillchar(prime,sizeof(prime),true); prime[1]:=false;
  for i:=2 to trunc(sqrt(maxn)) do
    if prime[i] then
      for j:=2 to maxn div i do prime[i*j]:=false;
  //now it's ready;
  for p:=13 to maxlongint do
    begin
      if not (prime[p] and prime[reverse(p)]) or (p=reverse(p)) then continue else dec(n);
      //writeln(p);
      if n=0 then begin writeln(p); halt; end;
    end;
end.
