const
  max=9973;

var
  t,kasus,n:longint;

function power(a,b:longint):longint;
  var
    temp:longint;

  begin
    if b=0 then power:=1
      else
        begin
          temp:=power(a,b div 2);
          if b mod 2=0 then power:=(temp*temp) mod max
            else power:=(temp*temp*a) mod max;
        end;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      writeln((5625*power(10,(n-4))) mod max);
    end;
end.