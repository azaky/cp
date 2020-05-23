var
  p:longint;

function pm(a,b:longint):longint;
  var
    ret:longint;
  
  begin
    if (b=0) then exit(1);
    ret := pm(a,b div 2);
    ret := (ret*ret) mod p;
    if (b mod 2=1) then ret := (ret*a) mod p;
    exit(ret);
  end;

begin
while true do begin
  readln(p);
  writeln(pm(4,545)+pm(5,454));
end;
end.
