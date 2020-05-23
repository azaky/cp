var
  x,y,ans,i,j:longint;
  m,n:string;

begin
  readln(x,y);
  str(x,m); str(y,n);
  ans:=0;
  for i:=1 to length(m) do
    for j:=1 to length(n) do
      ans:=ans+(ord(m[i])-ord('0'))*(ord(n[j])-ord('0'));
  writeln(ans);
end.
