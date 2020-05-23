const
  max=500000;

var
  n,i:longint;
  arr:array[1..max] of boolean;
  arrprime:array[1..max] of longint;

procedure sieve;
  var
    p,k:longint;

  begin
    arr[1]:=true;
    p:=2;
    while p<=trunc(sqrt(max)) do
      begin
        while arr[p] do inc(p);
        for k:=2 to max div p do
          arr[p*k]:=true;
        inc(p);
      end;
    n:=0;
    k:=2;
    for k:=1 to max do
      if not(arr[k]) then
        begin
          inc(n);
          arrprime[n]:=k;
        end;
  end;

begin
  sieve;
  writeln(arrprime[n]);
  randomize;
  writeln(random(88)+1);
  writeln(random(500000)+1);
end.
