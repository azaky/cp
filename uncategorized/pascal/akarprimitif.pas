var
  n,p,temp,count:longint;
  pi,q:array[1..10000000] of longint;

procedure factorize(n:longint);
  var
    i,j:longint;

  begin
    i:=1;
    p:=2;
    while n<>1 do
      begin
        while n mod p <> 0 do
          begin
            inc(p);
            inc(i);
          end;
        n:=n div p;
        pi[i]:=p;
        inc(q[i]);
      end;
    for j:=i downto 1 do if q[j]<>0 then inc(count);
  end;

begin
  readln(n);
  count:=0;
  if (n=2) or (n=4) then writeln('TRUE')
    else
      begin
        temp:=n;
        factorize(temp);
        if count=1 then
          if n mod 2 = 0 then writeln('FALSE')
            else writeln('TRUE')
          else if count=2 then
            if (n mod 2 = 0) and (n mod 4 <> 0) then writeln('TRUE')
              else writeln('FALSE')
          else writeln('FALSE');
      end;
end.