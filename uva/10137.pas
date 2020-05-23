uses math;
var
  n,i:longint;
  sum,ans1,ans2:double;
  a:array[0..11111] of double;

begin
  repeat
    readln(n); if n=0 then break;
    for i:=1 to n do readln(a[i]);
    sum := 0;
    for i:=1 to n do sum := sum+a[i];
    sum := sum/n;
    sum := double(round(100*sum))/100;
    ans1 := 0; ans2 := 0;
    for i:=1 to n do
      if a[i]>sum then ans1 := ans1 + a[i]-sum
      else ans2 := ans2 + sum-a[i];
    writeln('$',min(ans1,ans2):0:2);
  until eof;
end.
