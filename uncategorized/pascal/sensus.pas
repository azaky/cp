var
  n,m,i,j,a,b:longint;
  v:array[1..50000] of longint;

function max(a,b:longint):longint;
  begin
    if a>b then max:=a
      else max:=b;
  end;

function min(a,b:longint):longint;
  begin
    if a<b then min:=a
      else min:=b;
  end;

function maxv(a,b:longint):longint;
  begin
    if a=b then maxv:=v[a]
      else maxv:=max(maxv(a,((a+b) div 2)),maxv((1+((a+b) div 2)),b));
  end;

function minv(a,b:longint):longint;
  begin
    if a=b then minv:=v[a]
      else minv:=min(minv(a,((a+b) div 2)),minv((1+((a+b) div 2)),b));
  end;

begin
  readln(n,m);
  for i:=1 to n do readln(v[i]);
  for i:=1 to m do
    begin
      readln(a,b);
      writeln(maxv(a,b)-minv(a,b));
   end;
end.
