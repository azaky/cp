var
  i,m,n,kasus,tc:longint;
  t:int64;

function millerrabin(n,phase:int64):boolean;
  var
    s,r:longint;
    d,a,temp:int64;
    statement1,statement2:boolean;
  
  function power(a,b,c:int64):int64;
    var
      temp:int64;
    
    begin
      if b=0 then exit(1);
      temp:=power(a,b div 2,c);
      temp:=(temp*temp) mod c;
      if b mod 2=1 then temp:=(temp*a) mod c;
      exit(temp);
    end;
  
  begin
    if n=1 then exit(false);
    d:=n-1; s:=0; a:=random(n-1)+1;
    while d mod 2=0 do
      begin
        d:=d div 2; s:=s+1;
      end;
    temp:=power(a,d,n) mod n;
    statement1:=(temp-1) mod n<>0;
    statement2:=true;
    for r:=0 to s-1 do
      begin
        if (temp+1) mod n=0 then statement2:=false;
        temp:=(temp*temp) mod n;
      end;
    if statement1 and statement2 then exit(false);
    if phase=10 then exit(true);
    exit(millerrabin(n,phase+1));
    //exit(not (statement1 and statement2));
  end;

begin
  randomize;
  readln(tc);
  for kasus:=1 to tc do
    begin
      readln(m,n);
      for i:=m to n do
        begin
          t:=i;
          if millerrabin(t,1) then writeln(t);
        end;
      if kasus<tc then writeln;
    end;
end.

