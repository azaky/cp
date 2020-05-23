const
  suf:array[1..7] of string = ('lios','liala','etr','etra','initis','inites','');

var
  n,l,i,j,k,p,noun:longint;
  temp,s,t:ansistring;
  sentence:boolean;
  tp:array[1..100000] of longint;

begin
  n:=0;
      readln(s); l:=length(s);
	  temp:='';
	  for i:=1 to l do
	    begin
	      if s[i] in ['a'..'z'] then temp:=temp+s[i];
		  if ((s[i]=' ') or (i=l)) and (temp<>'') then
		      begin
		 	    inc(n); 
				t:=''; p:=length(temp);
				for k:=1 to 6 do
				  begin
					t:=temp[p]+t; dec(p);
					for j:=1 to 7 do
					  if t=suf[j] then break;
					if j<7 then
					  begin
					    tp[n]:=j; break;
					  end;
				  end;
				if tp[n]=0 then
				  begin
				    writeln('NO');halt;
				  end;
				temp:='';
		 	 end;
	    end;
  sentence:=true;
  if n=1 then
    begin
	  writeln('YES');halt;
	end;
  //check gender
  if tp[1] in [3,4] then noun:=1;
  for i:=2 to n do
    if (tp[1]-tp[i]) mod 2<>0 then
	  begin
	    sentence:=false; break;
	  end
	else if tp[i] in [3,4] then noun:=i;
  if not sentence then
    begin
	  writeln('NO'); halt;
	end;
  for i:=noun-1 downto 1 do
    if not (tp[i] in [1,2]) then
	  begin
	    sentence:=false; break;
	  end;
  for i:=noun+1 to n do
    if not (tp[i] in [5,6]) then
	  begin
	    sentence:=false; break;
	  end;
  if sentence then writeln('YES') else writeln('NO');
end.
