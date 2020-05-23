var
  n,k,a,i:longint;
  prob,best:extended;
  b,l:array[1..9] of longint;

procedure calc(pos,app,bb:longint; temp:extended);
  begin
    if pos=n then
	  begin
	    if app*2>n then prob:=prob+temp
		  else prob:=prob+a*temp/(a+bb);
		exit;
	  end
	else inc(pos); if temp=0 then exit;
	calc(pos,app+1,bb,temp*l[pos]/100);
	calc(pos,app,bb+b[pos],temp*(100-l[pos])/100);
  end;

procedure givecandy(pos,c:longint);
  begin
    if c=0 then
	  begin
	    prob:=0;
		calc(0,0,0,1.0000000000);
		if prob>best then best:=prob;
		exit;
	  end
	else if pos>n then exit;
	if l[pos]<100 then
	  begin
	    inc(l[pos],10);
		givecandy(pos,c-1);
		dec(l[pos],10);
	  end;
	givecandy(pos+1,c);
  end;

begin
  readln(n,k,a);
  for i:=1 to n do readln(b[i],l[i]);
  givecandy(0,k);
  writeln(best:0:10);
end.
