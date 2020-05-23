const
  maxn = 1000000;

var
  i,j,n,a,b:longint;
  best : record
    n,a,b:longint;
  end;
  prime:array[-maxn..maxn] of boolean;

begin
  //sieve algorithm
  for i:=2 to maxn do prime[i]:=true;
  for i:=2 to trunc(sqrt(maxn)) do
    if prime[i] then
      for j:=2 to (maxn div i) do prime[i*j]:=false;
  with best do
    begin
      n:=0; a:=0; b:=0;
    end;
  for a:=-10000 to 10000 do
    for b:=-10000 to 10000 do
      begin
        n:=1;
        while prime[sqr(n)+n*a+b] do inc(n);
        if n>best.n then
          begin
            best.n:=n; best.a:=a; best.b:=b;
          end;
      end;
  writeln(best.a:10,best.b:10,best.n:10,best.a*best.b:10);
end.
