uses math;

var
  kasus,tc,a,b,n,x,i:longint;

begin
  read(kasus);
  for tc:=1 to kasus do
    begin
      a := high(longint); b := low(longint);
      read(n);
      for i:=1 to n do begin read(x); a:=min(x,a); b:=max(x,b); end;
      writeln(b-a);
    end;
end.
