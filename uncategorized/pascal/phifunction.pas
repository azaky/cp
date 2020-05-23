var
  n:longint;

function phi(n:longint):longint;
  var
    p:longint;

  begin
    p:=2;
    phi:=n;
    while n>1 do
      begin
        while n mod p <> 0 do inc(p);
        phi:=(phi*(p-1)) div p;
        while n mod p = 0 do n:=n div p;
      end;
  end;

function primitive(n:longint):boolean;
  var
    p:longint;

  begin
    if (n=1) or (n=2) or (n=4) then primitive:=true
      else if n mod 4 = 0 then primitive:=false
        else
          begin
            while n mod 2 = 0 do n:=n div 2;
            p:=3;
            while n mod p <> 0 do inc(p);
            while n mod p = 0 do n:=n div p;
            if n=1 then primitive:=true else primitive:=false;
          end;
  end;

begin
  readln(n);
  if primitive(n) then writeln(phi(phi(n))) else writeln('0');
end.
