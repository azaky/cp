program ordo_keprimaan;

const
  max = 1000000;

var
  t,kasus,n:longint;
  f:array[1..max] of longint;
  prime:array[1..max] of boolean;
  fi:text;

procedure sieve;
  var
    i,j:longint;

  begin
    fillchar(prime,sizeof(prime),true);
    prime[1]:=false;
    for i:=2 to trunc(sqrt(max)) do if prime[i] then
      for j:=2 to (max div i) do prime[i*j]:=false;
    j:=1;
    for i:=1 to max do if prime[i] then
      begin
        f[i]:=j;
        inc(j);
      end;
  end;

function ordo(n:longint):longint;
  begin
    if not prime[n] then ordo:=0
      else ordo:=1+ordo(f[n]);
  end;

begin
  sieve;
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      writeln(ordo(n));
    end;
{
  assign(fi,'tes.out');
  rewrite(fi);
  for n:=1 to max do
    begin
      writeln(fi,'ordo(',n,') = ',ordo(n));
      if ordo(n)>kasus then
        begin
          t:=n;
          kasus:=ordo(n);
        end;
     end;
  writeln(fi,'ordo(',t,') = ',kasus);
  close(fi);
}
end.
