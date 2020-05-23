var
  n1,n2,p1,p2,ans,idle:longint;
  s1,s2:ansistring;

begin
  readln(s1); n1:=length(s1);
  readln(s2); n2:=length(s2);
  p1:=1; p2:=1; ans:=1; idle:=0;
  while true do
    begin
	  if s1[p1]=s2[p2] then
	    begin
		  inc(p2); idle:=0;
		  if p2>n2 then break;
		end
	  else inc(idle);
	  if idle=n1 then
	    begin
		  //writeln(p1,' ',p2,' ',ans,' ',idle);
		  ans:=-1;
		  break;
		end;
	  inc(p1);
	  if p1>n1 then
	    begin
		  p1:=1; inc(ans);
		end;
	end;
  writeln(ans);
end.
