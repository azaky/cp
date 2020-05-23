var
  n,i,q,k:longint;
  a:array[0..11111] of longint;
  com:array[0..1111,0..1111] of int64;

function sub(n,k:longint):int64;
  begin
    if (k=0) or (n=0) then exit(1)
      else if com[n,k]>=0 then exit(com[n,k]);
    com[n,k]:=(sub(n-1,k)+sub(n,k-1)) mod 1000000007;
    exit(com[n,k]);
  end;

begin
  fillchar(com,sizeof(com),255);
  readln(n);
  for i:=1 to n do read(a[i]);
  readln(q);
  for i:=1 to q do
    begin
      readln(k); writeln(sub(n-k,k-1));
    end;
end.
