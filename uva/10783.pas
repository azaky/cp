var
  tc,kasus,a,b:longint;

begin
  read(tc);
  for kasus:=1 to tc do
    begin
	  read(a,b); if a mod 2=0 then inc(a); if b mod 2=0 then dec(b);
	  writeln('Case ',kasus,': ',((b-a+2) div 2)*((a+b) div 2));
	end;
end.
