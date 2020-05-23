{
ID: a_zaky01
PROG: sprime
LANG: PASCAL
}

var
  n:integer;
  fin,fout:text;

function prime(p:longint):boolean;
  var
    i:longint;

  begin
    prime:=true;
    if (p<>2) and (p<>3) then
      for i:=2 to trunc(sqrt(p)) do
        if p mod i=0 then
          begin
            prime:=false;
            break;
          end;
  end;

procedure sprime(p:longint; k:integer);
  begin
    if prime(p) then
      if k=n then writeln(fout,p)
        else
          begin
            sprime((10*p+1),(k+1));
            sprime((10*p+3),(k+1));
            sprime((10*p+7),(k+1));
            sprime((10*p+9),(k+1));
          end;
  end;

begin
  assign(fin,'sprime.in');
  assign(fout,'sprime.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  sprime(2,1);
  sprime(3,1);
  sprime(5,1);
  sprime(7,1);
  close(fin);
  close(fout);
end.
