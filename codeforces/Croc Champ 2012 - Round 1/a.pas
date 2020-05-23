var
  n,m,k,i:longint;
  a,b:ansistring;
  p1,p2:array[-100..1111111] of longint;

function win(s,t:char):boolean;
  begin
    if s=t then exit(false)
    else exit(((s='P') and (t='R')) or ((s='R') and (t='S')) or ((s='S') and (t='P')));
  end;

begin
  readln(n);
  readln(a); readln(b);
  m:=length(a); k:=length(b);
  for i:=0 to m*k-1 do
    begin
      p1[i]:=p1[i-1]; p2[i]:=p2[i-1];
      if win(a[(i mod m)+1],b[(i mod k)+1]) then inc(p2[i])
      else if win(b[(i mod k)+1],a[(i mod m)+1]) then inc(p1[i]);
    end;
  writeln(p1[(n mod (m*k))-1]+(n div (m*k))*p1[m*k-1],' ',p2[(n mod (m*k))-1]+(n div (m*k))*p2[m*k-1]);
end.
