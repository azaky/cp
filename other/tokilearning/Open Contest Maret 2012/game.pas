var
  n,i,prime,ans:longint;

begin
  readln(n); ans:=maxlongint;
  for i:=2 to 1000000 do
    begin
      if (n>1) and (i*i>n) then
        begin
          inc(prime); if n<ans then ans:=n; break;
        end;
      if n mod i=0 then
        while n mod i=0 do
          begin
            if i<ans then ans:=i;
            n:=n div i; inc(prime);
          end;
      if n=1 then break;
    end;
  if prime mod 2=1 then writeln(ans) else writeln('menyerah');
end.
