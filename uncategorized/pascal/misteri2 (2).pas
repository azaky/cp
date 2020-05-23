var
  t,kasus,n,m,i:longint;
  a:array[2..10000] of longint;
 
function f(n,m:longint):longint;
  begin
    if n=m then f:=1
      else if (n<m) or (n<=1) then f:=0
        else
          begin
            if a[n]=-1 then a[n]:=(f(n-1,m)+f(n-2,m)) mod 10000;
            f:=a[n];
          end;
  end;
 
begin
  readln(t);
  for kasus:=1 to t do
    begin
      fillchar(a,sizeof(a),-1);
      readln(n,m);
      a[m]:=1;
      writeln(f(n,m));
    end;
end.
