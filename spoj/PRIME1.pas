var
  tc,kasus,a,b,i:longint;

function prime(a:longint):boolean;
  var
    i:longint;
  
  begin
    if a=1 then exit(false)
      else if a<4 then exit(true);
    for i:=2 to trunc(sqrt(a)) do
      if a mod i=0 then exit(false);
    exit(true);
  end;

begin
  readln(tc);
  for kasus:=1 to tc do
    begin
      readln(a,b);
      for i:=a to b do
        if prime(i) then writeln(i);
      if kasus<tc then writeln;
    end;
end.
