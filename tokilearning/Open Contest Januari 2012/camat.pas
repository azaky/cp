type
  matrix=array[0..3,0..3] of int64;

var
  n,a,b,c,m,ans:int64;
  f:array[0..3] of int64;
  init:matrix;

function product(a,b:matrix):matrix;
  var
    res:matrix;
    i,j,k:longint;
    
  begin
    fillchar(res,sizeof(res),0);
    for i:=1 to 3 do
      for j:=1 to 3 do
        for k:=1 to 3 do res[i,j]:=(res[i,j]+a[i,k]*b[k,j]) mod m;
    exit(res);
  end;

function power(m:matrix; n:int64):matrix;
  var
    res:matrix;
    
  begin
    if n=1 then exit(m);
    res:=power(m,n div 2); res:=product(res,res);
    if n mod 2=1 then res:=product(res,m);
    exit(res);
  end;

begin
  readln(n,f[1],f[2],a,b,c,m);
  f[3]:=(a*f[2]+b*f[1]+c) mod m;
  if n<4 then
    begin
      writeln(f[n]); halt;
    end;
  init[1,1]:=a; init[1,2]:=b;
  init[2,1]:=1; init[2,2]:=0;
  init:=power(init,n-1);
  ans:=(init[2,1]*f[2]+init[2,2]*f[1]) mod m;
  init[1,1]:=1; init[1,2]:=0; init[1,3]:=1;
  init[2,1]:=0; init[2,2]:=0; init[2,3]:=1;
  init[3,1]:=0; init[3,2]:=b; init[3,3]:=a;
  init:=power(init,n-2);
  ans:=(ans+(init[1,3])*c) mod m;
  writeln(ans);
end.
