type
  person = record
    dept,title,first,last,add,home,work,mail:string;
  end;

var
  d,n,z,i,len,k:longint;
  s:ansistring;
  temp:string;
  p:array[1..10000] of person;
  c:array[1..6] of longint;

procedure sort(l,r:longint);
  var
    i,j:longint;
	mid:string;
	temp:person;
  
  begin
    i:=l; j:=r; mid:=p[(l+r) div 2].last;
	repeat
	  while p[i].last<mid do inc(i);
	  while p[j].last>mid do dec(j);
	  if i>j then break;
	  temp:=p[i]; p[i]:=p[j]; p[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;
  
begin
  readln(d); n:=0;
  for z:=1 to d do
    begin
	  readln(temp);
	  while true do
	    begin
		  readln(s); if (length(s)=0) then break else inc(n);
		  len:=length(s); k:=0;
		  for i:=1 to len do
		    if s[i]=',' then
			  begin
			    inc(k); c[k]:=i;
				if k=6 then break;
			  end;
		  with p[n] do
		    begin
			  dept:=temp;
			  title:=copy(s,1,c[1]-1);
			  first:=copy(s,c[1]+1,c[2]-c[1]-1);
			  last :=copy(s,c[2]+1,c[3]-c[2]-1);
			  add  :=copy(s,c[3]+1,c[4]-c[3]-1);
			  home :=copy(s,c[4]+1,c[5]-c[4]-1);
			  work :=copy(s,c[5]+1,c[6]-c[5]-1);
			  mail :=copy(s,c[6]+1,len-c[6]);
			end;
		end;
	end;
  sort(1,n);
  for i:=1 to n do
    with p[i] do
      begin
		writeln('----------------------------------------');
	    writeln(title,' ',first,' ',last);
		writeln(add);
		writeln('Department: ',dept);
		writeln('Home Phone: ',home);
		writeln('Work Phone: ',work);
		writeln('Campus Box: ',mail);
	  end;
end.