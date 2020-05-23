const
  max=100;
  maxn=100;

var
  n,i:longint;
  a:array[1..max] of longint;
  arr:array[0..maxn,-max*maxn..max*maxn] of longint;
  stat:array[0..maxn,-max*maxn..max*maxn] of boolean;

function f(k,sum:longint):longint;
  begin
    f:=0;
    if (sum=0) and (k<>n) then f:=1
      else if k>0 then
        begin
          if not stat[k,sum] then
            begin
              stat[k,sum]:=true;
              arr[k,sum]:=f(k-1,sum)+f(k-1,sum-a[k]);
            end;
          f:=arr[k,sum];
        end;
  end;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  writeln(f(n,0));
end.
