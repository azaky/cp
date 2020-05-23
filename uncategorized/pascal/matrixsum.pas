var
  t,kasus,n,m,k,i,j,r,c,k0,best:longint;
  a:array[1..100,1..10] of integer;
  f:array[1..100,1..10,0..101] of longint;

function max(a,b:longint):longint;
  begin
    if a<=b then max:=b
      else max:=a;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n,m,k);
      for i:=1 to n do
        for j:=1 to m do read(a[i,j]);
      fillchar(f,sizeof(f),0);
      for c:=1 to m do
        for k0:=0 to k do f[1,c,k0]:=a[1,c];
      for r:=2 to n do
        for c:=1 to m do
          for k0:=0 to k do
            begin
              f[r,c,k0]:=-1;
              for i:=1 to m do
                if i=c then
                  f[r,c,k0]:=max(f[r-1,i,k0],f[r,c,k0])
                else f[r,c,k0]:=max(f[r-1,i,k0+1],f[r,c,k0]);
              inc(f[r,c,k0],a[r,c])
            end;
      best:=-1;
      for c:=1 to m do
        for k0:=0 to k do
          best:=max(best,f[n,c,k0]);
      writeln(best);
    end;
end.
