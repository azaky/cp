var
  i,j,ans:longint;

function pandigital(a,b,c:longint):boolean;
  var
    d:array[0..9] of longint;
    i:longint;
  
  begin
    fillchar(d,sizeof(d),0); d[0]:=1;
    while a>0 do
      begin
        if d[a mod 10]=1 then exit(false) else inc(d[a mod 10]);
        a:=a div 10;
      end;
    while b>0 do
      begin
        if d[b mod 10]=1 then exit(false) else inc(d[b mod 10]);
        b:=b div 10;
      end;
    while c>0 do
      begin
        if d[c mod 10]=1 then exit(false) else inc(d[c mod 10]);
        c:=c div 10;
      end;
    for i:=1 to 9 do
      if d[i]<>1 then exit(false);
    exit(true);
  end;

begin
  for i:=1234 to 9876 do
    begin
      for j:=2 to trunc(sqrt(i)) do
        if i mod j=0 then
          if pandigital(i,j,i div j) then
            begin
              writeln(j:4,' * ',i div j:4,' = ',i:4);
              ans:=ans+i;
              break;
            end;
    end;
  writeln(ans);
end.
