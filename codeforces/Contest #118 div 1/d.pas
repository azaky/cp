function pow(k,n,p:int64):int64;
  var
    res : int64;
  begin
    if n=0 then exit(k);
    res := pow(k,n-1,p);
    res := (res*res) mod p;
    exit(res);
  end;
function power(k,n,p:int64):int64;
  var
    res : int64;
  begin
    if n=0 then exit(1);
    res := power(k,n div 2,p);
    res := (res*res) mod p;
    if n mod 2=1 then res := (res*k) mod p;
    exit(res);
  end;
function inv(n,p:int64):int64;
  begin
    exit(power(n,p-2,p));
  end;

var
  tc,kasus:longint;
  k,l,r,p,a,b,c,res:int64;

begin
  readln(tc);
  for kasus:=1 to tc do
    begin
      readln(k,l,r,p);
      if p=2 then
        begin
          if k mod 2=1 then writeln(0) else writeln(1);
          continue;
        end;
      b := power(2,l,p-1)+(p-1);
      b := (power(k,b,p)+p-1) mod p;
      if b=0 then
        begin
          if k mod 2 = 0 then writeln(power(2,(r-l+1) mod (p-1),p))
            else writeln(2);
          continue;
        end;
      a := power(2,r+1,p-1)+(p-1);
      a := (power(k,a,p)+p-1) mod p;
      if k mod 2=0 then c := 1
        else
          begin
            c := (r-l) mod (p-1);
            c := (c*(p-2)) mod (p-1);
            c := power(2,c,p);
          end;
      b := inv(b,p);
      res := (((a*b) mod p)*c) mod p;
      writeln(res);
    end;
end.
