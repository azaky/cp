type
  bilangan=0..800;

var
  i,t,kasus,n:longint;
  f,sum:array[0..32] of longint;
  arr:array[1..2000000,1..32] of bilangan;

function basis(n,k:longint):longint;
  begin
    if n=0 then basis:=1
      else if (n<0) or (k<=0) or (n>sum[k]) then basis:=0
        else
          begin
            if arr[n,k]=0 then arr[n,k]:=basis(n,k-1)+basis(n-f[k],k-1);
            basis:=arr[n,k];
          end;
  end;

begin
  f[0]:=0;
  f[1]:=1;
  for i:=2 to 32 do f[i]:=f[i-1]+f[i-2];
  sum[1]:=f[1];
  for i:=2 to 32 do sum[i]:=sum[i-1]+f[i];
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      writeln(basis(n,32));
    end;
end.
