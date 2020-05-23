var
  seq:array[0..9999999] of int64;
  i,max:longint;

function collatz(n:int64):longint;
  var
    res:int64;
	
  begin
    if n=1 then exit(1);
	if (n<10000000) then
	  if (seq[n]>0) then exit(seq[n]);
	if n mod 2=0 then res:=1+collatz(n div 2)
	  else res:=1+collatz(3*n+1);
	if n<10000000 then seq[n]:=res;
	exit(res);
  end;

begin
  for i:=1 to 999999 do
    begin
	  seq[i]:=collatz(int64(i));
	  //writeln(i,'      ',seq[i]);
	  if seq[i]>seq[max] then
	    begin
		  max:=i;// writeln(max,' ',seq[max]);
		end;
	end;
  for i:=1 to 999999 do
    if seq[i]>seq[max] then max:=i;
  writeln(max);
end.
5
