const
  op:set of char = ['+','-','*','/','^'];

var
  t,i:longint;
  s:ansistring;

function rpn(l,r:longint):ansistring;
  var
    i,brackets:longint;
  
  begin
    if l=r then
	  begin
	    exit(s[l]);
	  end
    else if r-l=2 then
	  begin
	    exit(s[l]+s[r]+s[l+1]);
	  end
	else
	  begin
	    brackets:=-1;
		for i:=l to r do
		  if (brackets=0) and (s[i] in op) then
		    exit(rpn(l+1,i-1)+rpn(i+1,r-1)+s[i])
		  else if s[i]='(' then inc(brackets)
		    else if s[i]=')' then dec(brackets);
	  end;
  end;

begin
  readln(t);
  for i:=1 to t do
    begin
	  readln(s);
	  writeln(rpn(1,length(s)));
	end;
end.
