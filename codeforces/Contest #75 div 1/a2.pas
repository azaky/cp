var
  n1,n2,i,p1,p2,ans:longint;
  s1,s2:ansistring;
  ex:array['a'..'z'] of boolean;
  next:array[0..10001,'a'..'z'] of longint;

begin
  readln(s1); n1:=length(s1);
  readln(s2); n2:=length(s2);
  fillchar(next,sizeof(next),0);
  fillchar(ex,sizeof(ex),false);
  for i:=n1 downto 0 do
    begin
	  next[i]:=next[i+1];
	  next[i][s1[i+1]]:=i+1;
	  if i>0 then ex[s1[i]]:=true;
	end;
  p1:=0; ans:=1;
  for i:=1 to n2 do
    begin
	  if not ex[s2[i]] then
	    begin
		  writeln(-1);
		  halt;
		end;
	  p1:=next[p1,s2[i]];
	  if p1=0 then
	    begin
		  p1:=next[p1,s2[i]];
		  inc(ans);
		end;
	end;
  writeln(ans);
end.
