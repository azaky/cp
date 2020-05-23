var
  i,n,d,j,k,ans,p:longint;
  box:array[1..30,1..10] of longint;
  fit:array[1..30,1..30] of boolean;
  max,next:array[1..30] of longint;
  flag:array[1..30] of boolean;

procedure qsort(k:longint);
  procedure sort(l,r:longint);
    var
	  i,j,temp,mid:longint;
	
	begin
	  i:=l; j:=r; mid:=box[k][(l+r) div 2];
	  repeat
	    while box[k][i]<mid do inc(i);
		while box[k][j]>mid do dec(j);
		if i>j then break else temp:=box[k][i]; box[k][i]:=box[k][j]; box[k][j]:=temp;
		inc(i); dec(j);
	  until i>j;
	  if l<j then sort(l,j);
	  if i<r then sort(i,r);
	end;
  
  begin
    sort(1,d);
  end;

function nest(a:longint):longint;
  var
    i,temp:longint;
  
  begin
    if flag[a] then exit(max[a]) else flag[a]:=true;
    max[a]:=0;
	for i:=1 to n do
	  begin
	    if (a=i) or (not fit[a,i]) then continue;
		temp:=nest(i);
		if temp>max[a] then
		  begin
		    max[a]:=temp;
		    next[a]:=i;
		  end;
	  end;
	inc(max[a]); exit(max[a]);
  end;
  
begin
  for i:=1 to 30 do fit[i,i]:=true;
  repeat
    readln(n,d);
	for i:=1 to n do
	  begin
	    for j:=1 to d do read(box[i][j]); readln;
		qsort(i);
	  end;
	for i:=1 to n do
	  for j:=1 to n do
	    begin
		  if i=j then continue else fit[i,j]:=true;
		  for k:=1 to d do
		    if box[i][k]>=box[j][k] then
			  begin
			    fit[i,j]:=false; break;
			  end;
		end;
	fillchar(flag,sizeof(flag),false); ans:=0;
	for i:=1 to n do max[i]:=nest(i);
	for i:=1 to n do
	  if max[i]>max[ans] then ans:=i;
	writeln(max[ans]); p:=ans;
	for i:=1 to max[ans] do
	  begin
	    write(p); p:=next[p];
		if i=max[ans] then writeln else write(' ');
	  end;
  until eof;
end.
