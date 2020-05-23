const
  max = 1000000007;

var
  t,kasus,p,i:longint;
  a,b,hasil:int64;

function f(a,b:int64):int64;
  var
    temp,temp2:int64;

  begin
    if b=0 then f:=1
      else if b mod 2=0 then f:=(1+a*(f(a,b-1))) mod max
        else
          begin
            temp:=f(a,(b-1) div 2);
            temp2:=(temp*(a-1)+2) mod max;
            f:=(temp*temp2) mod max;
          end;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(a,b);
      if a=0 then if b=0 then writeln('1') else writeln('0')
      else if (a=1) or (b=0) then writeln('1')
        else
          begin
            hasil:=1;
            p:=2;
            while a<>1 do
              begin
                i:=0;
                while a mod p<>0 do
                  if p>sqrt(a) then p:=a
                    else if p=2 then inc(p)
                      else p:=p+2;
                while a mod p=0 do
                  begin
                    inc(i);
                    a:=a div p;
                  end;
                hasil:=(hasil*f(p,b*i)) mod max;
              end;
            writeln(hasil);
          end;
    end;
end.
