var
  sa,sb:string;
  a,b,best,i,cur,j:integer;

begin
  readln(sa); readln(sb);
  a:=length(sa); b:=length(sb);
  best:=10000;
  for i:=0 to b-a do
    begin
	  cur:=0;
	  for j:=1 to a do
	    if sa[j]<>sb[i+j] then inc(cur);
	  if cur<best then best:=cur;
	end;
  writeln(best);
end.
