var
  n:int64;

function f(n:int64):int64;
  var
    p,t:int64;
    
  begin
    if n<=3 then exit(n)
      else if n<=5 then exit(5)
        else if n mod 2=1 then exit(f(n-1))
          else if n mod 4=0 then exit((2*f(n div 2)) mod 12345)
            else
              begin
                p:=trunc(ln(n)/ln(2));
                t:=trunc(exp(p*ln(2)));
                if n>(3*t div 2) then exit((2+f(n-2)) mod 12345)
                  else exit((3+f(n-2)) mod 12345);
              end;
          //exit((f(n div 2)+f((n+2) div 2)) mod 12345);
  end;

begin
  readln(n);
  writeln(f(n));
end.
{
observation

f(7) = f(3)+f(4)
     = f(1)+f(2)+f(2)+f(3)
     = f(1)+f(2)+f(2)+f(1)+f(2)
     = 2*f(1)+3*f(2)

f(8) = f(4)+f(5)
     = f(2)+f(3)+f(2)+f(3)
     = 2*f(2)+2*(f(1)+f(2))
     = 2*f(1)+4*f(2)

f(9) = f(4)+f(5)
     = ...

:: f(2n)=f(2n+1)

:: f(4k)=f(4k+1)=2*f(2k)

f(4k+2) = f(2k+1)+f(2k+2)
        = f(2k)+f(k+1)+f(k+2)
        = f(k)+2*f(k+1)+f(k+2) --"

f(4k) = 2(f(2k))
      = 2(f(k)+f(k+1))

f(4k+2)-f(4k)=f(k+2)-f(k) -_______-

...

after a long long observation, I can conclude my solution above
}
