var
  n,i:longint;

function prime(x:longint):boolean;
  var
    v,i:longint;

  begin
    v:=0;
    for i:=1 to trunc(sqrt(x)) do if x mod i = 0 then v:=v+1;
    if v=1 then prime:=true else prime:=false;
  end;

begin
  readln(n);
  {if n=4 then writeln('4 = 2 + 2')
    else for i:=1 to n div 4 do
      if (prime(2*i+1)=true) and (prime(n-2*i-1)=true) then break;
  if n<>4 then writeln(n,' = ',2*i+1,' + ',n-2*i-1);}
  if prime(n) then writeln('true');
end.
