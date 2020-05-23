var
  n,m,i,k:longint;
  basket:array[0..111111] of longint;

begin
  readln(n,m);
  if m mod 2=0 then
    begin
      for i:=1 to n do
        begin
          k := ((i-1) mod m)+1;
          if k=1 then basket[i]:=m div 2
            else if k=2 then basket[i]:=(m div 2)+1
              else if k mod 2=0 then basket[i] := basket[i-2]+1
                else if k mod 2=1 then basket[i] := basket[i-2]-1;
        end;
    end
  else
    begin
      for i:=1 to n do
        begin
          k := ((i-1) mod m)+1;
          if k=1 then basket[i]:=(m+1) div 2
            else if k=2 then basket[i]:=(m div 2)
              else if k mod 2=0 then basket[i] := basket[i-2]-1
                else if k mod 2=1 then basket[i] := basket[i-2]+1;
        end;
    end;
  for i:=1 to n do writeln(basket[i]);
end.
