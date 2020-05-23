uses math;
const eps = 1e-14;

var
  p,q,r,s,t,u,a,b,mid:double;

function f(x:double):double;
  begin
    exit(p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*sqr(x) + u);
  end;

begin
  repeat
    readln(p,q,r,s,t,u);
    if abs(f(0))<eps then begin writeln('0.0000'); continue; end;
    if abs(f(1))<eps then begin writeln('1.0000'); continue; end;
    if f(0)*f(1)+eps>0 then begin writeln('No solution'); continue; end;
    a := 0; b := 1;
    repeat
      mid := (a+b)/2;
      if f(0)*f(mid)+eps>0 then a:=mid else b:=mid;
    until abs(a-b)<eps;
    writeln(mid:0:4);
  until eof;
end.
