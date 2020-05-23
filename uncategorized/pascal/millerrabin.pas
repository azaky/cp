const
  maxtest = 5000;
  maxnum = 1000000000000000000;

var
  i:longint;
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
    if phase=1000 then exit(true);
    exit(millerrabin(n,phase+1));
    //exit(not (statement1 and statement2));
  end;

function prime(n:int64):boolean;
  var
    i:longint;
  
  begin
    if n=1 then exit(false);
    for i:=2 to trunc(sqrt(n)) do
      if n mod i=0 then exit(false);
    exit(true);
  end;

begin
  randomize;
  for i:=1 to maxtest do
    begin
      //t:=random(maxnum)+1;
      readln(t);
      if millerrabin(t,1) then writeln(t);
      //if millerrabin(t,1) xor prime(t) then writeln('ERROR ',t);
    end;
end.

