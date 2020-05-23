var
  a,b,i,t,max:longint;
  flag:array[1..1000000] of boolean;
  p:array[1..1000000] of longint;

function cycle(a:longint):longint;
  begin
    if a<1000000 then
	  if flag[a] then exit(p[a]);
	if a=1 then cycle:=1
	  else if a mod 2=1 then cycle:=1+cycle(3*a+1)
	    else cycle:=1+cycle(a div 2);
    if a<1000000 then
	  begin
	    flag[a]:=true; p[a]:=cycle;
	  end;
  end;

begin
  while not eof do
    begin
	  readln(a,b); max:=0;
	  if a<=b then
   	    for i:=a to b do
	      begin
		    t:=cycle(i);
		    if t>max then max:=t;
		  end
		else for i:=b to a do
	      begin
		    t:=cycle(i);
		    if t>max then max:=t;
		  end;
      writeln(a,' ',b,' ',max);
	end;
end.
