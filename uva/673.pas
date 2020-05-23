var
  tc,kasus,k,i,n:integer;
  yes:boolean;
  l:array[-128..0] of integer;
  s:string;

function match(a,b:integer):boolean;
  begin
    exit(((s[a]='(') and (s[b]=')')) or ((s[a]='[') and (s[b]=']')));
  end;

begin
  readln(tc);
  for kasus:=1 to tc do
    begin
	  readln(s); n:=length(s); k:=0; yes:=n mod 2=0;
	  for i:=1 to n do
	    begin
		  if s[i] in ['(','['] then
		    begin
			  dec(k);
			  l[k]:=i;
			end
		  else
		    begin
			  inc(k);
			  if (k>0) then yes:=false
			    else if not match(l[k-1],i) then yes:=false;
			end;
		  if not yes or (n-i+k<0) then break;
		end;
	  yes:=yes and (k=0);
	  if yes then writeln('Yes') else writeln('No');
	end;
end.
