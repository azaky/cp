var
  n,k,i,ans:longint;
  sum:int64;
  a:array[1..1000000] of longint;
  p:array[0..51] of int64;

begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  //precompute the powers of two
  p[0]:=1;
  for i:=1 to 51 do p[i]:=2*p[i-1];
  //calculate the first k-sum
  sum:=0;
  for i:=1 to k do sum:=sum+p[a[i]];
  //check all the n-k+1 sums
  for i:=k+1 to n do
    begin
      if sum=p[k+1]-2 then inc(ans);
      sum:=sum+p[a[i]]-p[a[i-k]];
    end;
  writeln(ans);
end.
