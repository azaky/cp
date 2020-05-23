var
  a,p,pangkat:longint;
  stat:boolean;

function prime(p:longint):boolean;
  var
    i:longint;

  begin
    prime:=true;
    if p=1 then prime:=false
      else for i:=2 to trunc(sqrt(p)) do
        if p mod i = 0 then
          begin
            prime:=false;
            break;
          end;
  end;

function powermod(a,pangkat,modulo:longint):longint;
  var
    temp:longint;

  begin
    if pangkat=0 then powermod:=1
      else if pangkat=1 then powermod:=a mod modulo
        else
          begin
            temp:=powermod(a,pangkat div 2,modulo);
            if pangkat mod 2 = 0 then powermod:=(temp*temp) mod modulo
              else powermod:=(temp*temp*a) mod modulo;
          end;
  end;

begin
  readln(a);
  p:=3;
  stat:=true;
  while stat do
    begin
      inc(p);
      pangkat:=powermod(a,p-1,p);
      if (pangkat=1) and not(prime(p)) then
        begin
          stat:=false;
          writeln(p);
        end;
    end;
end.
