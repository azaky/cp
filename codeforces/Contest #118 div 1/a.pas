const m = 1000000007;

var
  n:int64;

function p(n:int64):int64;
  var
    res:int64;
  begin
    if n=0 then exit(1);
    res := p(n div 2);
    res := (res*res) mod m;
    if n mod 2=1 then res := (res*2) mod m;
    exit(res);
  end;

begin
  readln(n);
  if n=0 then writeln(1) else writeln((p(2*n-1)+p(n-1)) mod m);
end.
