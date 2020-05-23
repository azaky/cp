const
  f:array[0..11] of boolean=(true,false,false,true,false,false,true,true,false,true,true,false);

var
  a,n,best,temp:int64;
  b,b0,c,c0,m,i:longint;
  z:array[0..231] of longint;


function max(a,b:int64):int64;
  begin
    if a>b then exit(a)
      else exit(b);
  end;

begin
  readln(n);
{
  The problem actually states that if a, b, c are nonnegative integers satisfying 11*a+3*b+7*c=N,
  then find the maximum value of 19*a+2*b+5*c.
  Here we will use linear diophantine equation. Note that the value is maximal when the value of
  a is maximal.
  
}

  if n<11 then
    begin
      writeln(-1);
      halt;
    end;

  fillchar(z,sizeof(z),255);
  z[11]:=19;
  for i:=1 to 231 do
    begin
      if (i>=3) then
        if (z[i-3]>=0) then z[i]:=max(z[i],z[i-3]+2);
      if (i>=7) then
        if (z[i-7]>=0) then z[i]:=max(z[i],z[i-7]+5);
      if (i>=11) then
        if (z[i-11]>=0) then z[i]:=max(z[i],z[i-11]+19);
    end;
    
  temp:=231*(n div 231);
  best:=z[n-temp]+19*(temp div 11);
  writeln(best);

{
  m:=n-11*(n div 11);
  if not f[m] then inc(m,11);
  if n-m<0 then
    begin
      writeln(-1);
      halt;
    end;
  
  a:=(n-m) div 11;
  
  best:=-1;
  for b0:=0 to (m div 3) do
    begin
      if (m-3*b0) mod 7<>0 then continue;
      c0:=(m-3*b0) div 7;
      temp:=2*b0+5*c0;
      if temp>best then
        begin
          best:=temp;
          b:=b0; c:=c0;
        end;
    end;
  
  best:=19*a+2*b+5*c;
  writeln(best);
}
end.

