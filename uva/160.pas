const
  p:array[1..25] of longint = (2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97);

var
  i,j,t,n:longint;
  fact:array[0..100,0..26] of longint;

begin
  for i:=2 to 100 do
    begin
	  t:=i; fact[i]:=fact[i-1];
	  for j:=1 to 25 do
	    if t mod p[j]=0 then
		  begin
		    while t mod p[j]=0 do
			  begin
			    t:=t div p[j];
				inc(fact[i][j]);
			  end;
		  end;
	end;
  repeat
    readln(n); if n=0 then break;
	write(n:3,'! =');
	for i:=1 to 25 do
	  if fact[n][i]=0 then break
	    else if (i mod 15=1) and (i>1) then
		  begin
		    writeln;write(fact[n][i]:9);
		  end
		else write(fact[n][i]:3);
	writeln;
  until false;
end.
//00:07:23.782