var
  n,k,i,p:longint;
  a,prev:array[0..500005] of longint;
  del:array[0..500005] of boolean;
  ch:char;

begin
  readln(n,k);
  for i:=1 to n do
    begin
      read(ch); a[i]:=ord(ch)-ord('0');
      prev[i]:=i-1;
    end;
  p:=2; a[0]:=11;
  while k>0 do
    begin
      if a[p]>a[prev[p]] then
        begin
          dec(k); del[prev[p]]:=true;
          prev[p]:=prev[prev[p]];
        end
      else p:=p+1;
      if p>n then break;
    end;
  p:=0;
  for i:=1 to n do
    if not del[i] then
      begin
        inc(p); a[p]:=a[i];
      end;
  for i:=1 to p-k do write(a[i]);writeln;
end.
