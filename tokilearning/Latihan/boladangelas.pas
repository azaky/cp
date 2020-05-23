var
  n,m,a,b,i,q,x,temp:longint;
  num:array[1..100000] of longint;

begin
  readln(n,m);
  for i:=1 to n do num[i]:=i;
  for i:=1 to m do
    begin
      readln(a,b);
      temp:=num[a];
      num[a]:=num[b];
      num[b]:=temp;
    end;
  readln(q);
  for i:=1 to q do
    begin
      readln(x);
      writeln(num[x]);
    end;
end.
