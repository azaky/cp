var
  n:longint;

begin
  readln(n);
  //x^2+x-2n=0
  writeln(trunc((sqrt(8*n+1)-1)/2)+1);
end.

