var
  a,b,c,d,polab,temp,j:longint;

procedure pola(a:longint);
  var
    slot,temp:array[1..100] of byte;
    sisa,i:longint;
    stat,stat2:boolean;

  begin
    sisa:=1;
    i:=0;
    stat:=true;
    stat2:=true;
    while stat do
      begin
        sisa:=(sisa*a) mod 100;
        inc(i);
        inc(slot[sisa]);
        temp[i]:=sisa;
        if slot[sisa]=2 then
          begin
            stat:=false;
            while stat2 do
              begin
                inc(j);
                if temp[j] = sisa then stat2:=false;
              end;
            polab:=i-j;
          end;
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
          if pangkat mod 2=0 then powermod:=(temp*temp) mod modulo;
          if pangkat mod 2=1 then powermod:=(temp*temp*a) mod modulo;
        end;
  end;

function powerge(a,pangkat,x:longint):boolean;
  var
    hasil,i:longint;

  begin
    powerge:=false;
    hasil:=1;
    if pangkat=0 then
      if hasil>=x then powerge:=true
        else powerge:=false
      else
        for i:=1 to pangkat do
          begin
            hasil:=hasil*a;
            if hasil>=x then
              begin
                powerge:=true;
                break;
              end;
          end;
  end;

begin
  readln(a,b,c,d);
  a:=a mod 101;
  b:=b mod 100;
  j:=0;
  if a = 0 then writeln(0)
    else
      begin
        pola(b);
        if j=1 then
          begin
            temp:=powermod(c,d,polab);
            temp:=powermod(b,temp,100);
            temp:=powermod(a,temp,101);
            writeln(temp);
          end
        else if powerge(c,d,j) then
          begin
            temp:=(powermod(c,d,polab)+j) mod polab;
            temp:=powermod(b,temp,100);
            temp:=powermod(a,temp,101);
            writeln(temp);
          end
        else
          begin
            temp:=powermod(c,d,j);
            temp:=powermod(b,temp,100);
            temp:=powermod(a,temp,101);
            writeln(temp);
          end;
      end;
end.
