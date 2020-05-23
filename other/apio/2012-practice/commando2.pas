uses math;

var
  n,i:longint;
  a,b,c,ans:int64;
  x:array[0..1000000] of int64;

begin
  readln(n); readln(a,b,c);
  for i:=1 to n do read(x[i]);
  //if c>=0 then
  for i:=1 to n do ans:=ans+a*x[i]*x[i]+b*x[i]+c;
  writeln(ans,' ',c);
end.
