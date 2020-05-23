var
  n,m,temp:longint;

begin
  readln(n,m);
  if n>m then
    begin
	  temp:=n; n:=m; m:=temp;
	end;
  if n=1 then
    begin
	  writeln(m-((m+2) div 3)); halt;
	end;
  if n=2 then
    begin
	  writeln(2*m-((m+2) div 2)); halt;
	end;
  if n=3 then
    begin
	  case m of
	    3:writeln(6);//3
		4:writeln(8);//4
		5:writeln(11);//4
		6:writeln(13);//5
		7:writeln(15);//6
		8:writeln(17);//7
		9:writeln(20);//7
		10:writeln(22);//8
		11:writeln(24);//9
		12:writeln(26);//10
		13:writeln(29);//10
	  end;
	  halt;
	end;
  if n=4 then
    begin
	  case m of
	    4:writeln(12);//4
		5:writeln(14);//6
		6:writeln(17);//7
		7:writeln(21);//7
		8:writeln(24);//8
		9:writeln(26);//10
		10:writeln(30);//10
	  end;
	  halt;
	end;
  if n=5 then
    begin
	  case m of
	    5:writeln(18);//7
		6:writeln(22);//8
		7:writeln(26);//9
		8:writeln(29);//11
	  end;
	  halt;
	end;
  writeln(26);
end.
