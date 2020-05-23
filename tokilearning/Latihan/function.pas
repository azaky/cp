var
  n:integer;

function fact(x:integer):longint;
  begin
    if x=0 then exit(1)
      else exit(x*fact(x-1));
  end;

begin
  readln(n);
  if (n<0) or (n>10) then writeln('ditolak')
    else writeln(fact(n));
end.
