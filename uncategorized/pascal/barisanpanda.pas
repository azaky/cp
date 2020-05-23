const
  max=1000007;

var
  t,kasus,n,k:longint;
  arr:array[1..200,1..20100] of longint;

function f(n,k:longint):longint;
  var
    i:longint;

  begin
    if (k<0) or (k>((n*(n-1)) div 2)) or (n=0) then f:=0
      else if (k=0) or (k=(n*(n-1)) div 2) then f:=1
        else
          begin
            if arr[n,k]=0 then
              for i:=k downto k-n+1 do arr[n,k]:=(arr[n,k]+f(n-1,i)) mod max;
            f:=arr[n,k];
          end;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n,k);
      writeln(f(n,k));
    end;
end.
