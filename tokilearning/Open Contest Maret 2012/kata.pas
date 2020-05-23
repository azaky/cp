const
  mmm = 1000000007;

var
  i,j,n:longint; ans:int64;
  //com:array[0..1111,0..1111] of longint;
  fact:array[0..1000001] of int64;
  
function pow(a,b:longint):int64;
  begin
    if b=0 then exit(1);
    pow:=pow(a,b div 2); pow:=(pow*pow) mod mmm;
    if b mod 2=1 then pow:=(pow*a) mod mmm;
  end;
  
begin
  fact[0]:=1;
  for i:=1 to 1000000 do fact[i]:=(fact[i-1]*i) mod mmm;
  {
  com[0,0]:=1;
  for i:=1 to 1111 do
    begin com[i,0]:=1; com[0,i]:=1; end;
  for i:=1 to 1111 do
    for j:=1 to 1111 do
      com[i,j]:=(com[i-1,j]+com[i,j-1]) mod 1000000007;
  }
  readln(n);
  ans:=1;
  for i:=1 to (n+2) div 3 do
    begin
      ans:=(ans+((fact[n-2*(i-1)]*pow(fact[i],mmm-2)) mod mmm)*pow(fact[n-2*(i-1)-i],mmm-2)) mod mmm;
      //ans:=(ans+com[n-2*(i-1)-i,i]) mod 1000000007;
    end;
  writeln(ans);
end.
