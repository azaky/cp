var
  n,i,k:longint;
  total:int64;
  a:array[0..100001] of integer;
  s:array[0..100001] of longint;
  destroy:array[0..100001] of boolean;

begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  a[0]:=10001;
  a[n+1]:=10001;
  k:=1;
  s[0]:=0;
  s[1]:=1;
  s[2]:=2;
  total:=0;
  while true do
    begin
      while (a[s[k+1]]<=a[s[k]]) and (s[k+1]<=n) do
        begin
          inc(k);
          s[k+1]:=s[k]+1;
          while destroy[s[k+1]] do inc(s[k+1]);
        end;
      if s[k+1]>n then
        begin
          for i:=1 to n-1 do
            if not destroy[i] then total:=total+a[i];
          break;
        end
      else
        begin
          if a[s[k-1]]<a[s[k+1]] then total:=total+a[s[k-1]]
            else total:=total+a[s[k+1]];
          destroy[s[k]]:=true;
          s[k]:=s[k+1];
          dec(k);
        end;
    end;
  writeln(total);
end.
