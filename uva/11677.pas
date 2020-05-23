var
  a,b,c,d,ans:longint;

begin
  while true do
    begin
	  readln(a,b,c,d); if (a+b+c+d=0) then break;
	  ans:=60*(c-a)+(d-b); if ans<0 then ans:=ans+1440;
	  writeln(ans);
	end;
end.