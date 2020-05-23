var
p,l,n,q,x,y,k,i,j:longint;
a:array[1..1000,1..1000] of longint;
s:string;

begin
readln(p,l);
readln(n);
for i:=1 to n do
  begin
  readln(x,y,k);
  q:=1;
  while q>0 do
    begin
    if (x<=p) and (y<=l) then
      q:=0;
    if (x>p) or (y>l) then
      begin
      writeln('Invalid entry. Please try again.');
      readln(x,y,k);
      end;
    end;
  a[x,y]:=k;
  end;
for k:=1 to l do
  begin
  for i:=1 to p do
    begin
    q:=1;
    for j:=1 to l do
      begin
      str(a[i,j],s);
      if length(s)>q then q:=length(s);
      end;
    q:=q+1;
    write(a[i,k]);
    str(a[i,k],s);
    for j:=1 to q-length(s) do
      begin
      if i<>p then write(' ')
      else
        begin
        writeln;
        break;
        end;
      end;
    end;
  end;
end.