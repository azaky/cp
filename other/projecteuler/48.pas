const
  maxn = 10000000000;

var
  ans:int64;
  i:longint;

function pow(a,b:int64):int64;
  begin
    if b=1 then exit(a);
    temp:=pow(a,b div 2); temp:=sqr(temp) mod maxn;
    if b mod 2=1 then pow:=(pow*a) mod maxn;
  end;

begin
  ans:=0;
  for i:=1 to 1000 do ans:=ans+pow(int64(i),int64(i));
  writeln(ans mod maxn);
end.
