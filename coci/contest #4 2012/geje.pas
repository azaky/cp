var
  i,n,p:longint;
  next,prev:array[0..11111] of longint;

function f(n:longint):longint;
  begin
    if n=1 then exit(1)
      else if n mod 2=0 then exit(2*f(n div 2)-1)
        else exit(2*f(n div 2)+1);
  end;

begin
  for n:=1 to 1000 do begin
  //naive algorithm
  for i:=1 to n-1 do next[i]:=i+1;
  next[n]:=1;
  for i:=2 to n do prev[i]:=i-1;
  prev[1]:=n;
  p:=2;
  for i:=1 to n-1 do
    begin
      prev[next[p]]:=prev[p];
      next[prev[p]]:=next[p];
      p:=next[next[p]];
    end;
    if (n>1) and (p<>f(n)) then writeln('found!: ',n);
  end;
end.
