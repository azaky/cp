var
  a,b,c,d,polab,temp:longint;

function pola(a,modulo:longint):longint;
  var
    sisa,i:longint;
    stat:boolean;

  begin
    sisa:=a;
    i:=0;
    stat:=true;
    while stat do
      begin
        sisa:=(sisa*a) mod modulo;
        inc(i);
        if sisa=a then stat:=false;
        if i>modulo then
          begin
            i:=0;
            stat:=false;
          end;
      end;
    pola:=i;
  end;

function power(a,pangkat,modulo:longint):longint;
  var
    temp:longint;

  begin
    if pangkat=0 then power:=1
    else if pangkat=1 then power:=a mod modulo
      else
        begin
          temp:=power(a,pangkat div 2,modulo);
          if pangkat mod 2=0 then power:=(temp*temp) mod modulo;
          if pangkat mod 2=1 then power:=(temp*temp*a) mod modulo;
        end;
  end;

begin
  readln(a,b,c,d);
  a:=a mod 101;
  b:=b mod 100;
  if a = 0 then writeln(0)
    else
      begin
        polab:=pola(b,100);
        if polab=0 then

          else
            begin
              c:=c mod polab;
              temp:=power(c,d,polab);
              temp:=power(b,temp,100);
              temp:=power(a,temp,101);
              writeln(temp);
            end;
      end;
end.
