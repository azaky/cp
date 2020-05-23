var
  a,b,c,n,pola1,pola2,temp,i,j:longint;

procedure pola(a,modulo:longint);
  var
    slot,temp:array[0..30000] of longint;
    sisa,i,k:longint;
    stat,stat2:boolean;

  begin
    sisa:=1;
    i:=0;
    stat:=true;
    stat2:=true;
    for k:=0 to modulo do slot[k]:=0;
    while stat do
      begin
        sisa:=(sisa*a) mod modulo;
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
            pola1:=i-j;
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
          temp:=powermod(a,pangkat div 2,modulo) mod modulo;
          if pangkat mod 2=0 then powermod:=(temp*temp) mod modulo;
          if pangkat mod 2=1 then powermod:=(temp*temp*a) mod modulo;
        end;
    if powermod=0 then powermod:=modulo;
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
  readln(a,b,c,n);
  if a=0 then writeln('1')
    else if b=0 then writeln('2')
      else if c=0 then writeln((a mod n)+1)
        else
          begin
            pola(a,n);
            if j=1 then
              begin
                temp:=powermod(b,c,pola1);
                temp:=powermod(a,temp,n);
                if temp=n then temp:=0;
                writeln(temp+1);
              end
            else if powerge(b,c,j) then
              begin
                temp:=(powermod(b,c,pola1)-j+1) mod pola1;
                while temp<0 do temp:=temp+pola1;
                if temp=0 then temp:=pola1;
                temp:=powermod(a,(temp+j-1),n);
                if temp=n then temp:=0;
                writeln(temp+1);
              end
            else
              begin
                temp:=powermod(b,c,j);
                temp:=powermod(a,temp,n);
                if temp=n then temp:=0;
                writeln(temp+1);
              end;
          end;
end.
