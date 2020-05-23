const
  wave:array[1..9] of string = ('1','22','333','4444','55555','666666','7777777','88888888','999999999');

var
  tc,kasus,A,f,i,j:longint;

begin
  readln(tc);
  for kasus:=1 to tc do
    begin
	  readln(A); readln(f);
	  for i:=1 to f do
	    begin
		  for j:=1 to A do writeln(wave[j]);;
		  for j:=A-1 downto 1 do writeln(wave[j]);
		  if i<f then writeln;
		end;
	  if kasus<tc then writeln;
	end;
end.
