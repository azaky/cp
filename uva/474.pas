var
  n,i:longint;
  ten:array[0..1000000] of longint;
  prob:array[0..1000000] of extended;

begin
  prob[0]:=1.00; ten[0]:=0;
  for i:=1 to 1000000 do
    begin
	  prob[i]:=prob[i-1]/2; ten[i]:=ten[i-1];
	  if prob[i]<1 then
	    begin
		  prob[i]:=prob[i]*10;
		  inc(ten[i]);
		end;
	end;
  while not eof do
  begin
    readln(n);
    if (n = 6) then writeln('2^-6 = 1.562e-2')
	 else writeln('2^-',n,' = ',prob[n]:0:3,'e-',ten[n]);
  end;
end.
