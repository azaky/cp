program sort;

const
max = 1000000;

type
aray = array[1..max] of longint;

var
z:aray;
i,N,input:longint;

procedure swap(var a,b:longint);
  var
  c:longint;

  begin
  c:=a;
  a:=b;
  b:=c;
  end;

procedure bsort(var n:longint);
  var
  i,j:longint;

  begin
  for i:=1 to n-1 do
    begin
    for j:=i+1 to n do
      begin
      if z[i]>z[j] then swap(z[i],z[j]);
      end;
    end;
  end;

begin
readln(N);
for i:=1 to N do
  begin
  readln(input);
  z[i]:=input;
  end;
bsort(N);
for i:=1 to N do write(z[i],' ');
end.
