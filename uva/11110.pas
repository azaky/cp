var
  n,i,j,x,y:longint;
  good:boolean;
  visit:array[0..100,0..100] of boolean;
  a:array[0..100,0..100] of longint;

label
  answer;

procedure fill(i,j:longint);
  begin
    if (i=0) or (j=0) or (i>n) or (j>n) or visit[i,j] then exit else visit[i,j]:=true;
	inc(x);
	if a[i-1,j]=a[i,j] then fill(i-1,j);
	if a[i+1,j]=a[i,j] then fill(i+1,j);
	if a[i,j-1]=a[i,j] then fill(i,j-1);
	if a[i,j+1]=a[i,j] then fill(i,j+1);
  end;

begin
  repeat
    readln(n); if n=0 then break else good:=true;
	fillchar(a,sizeof(a),0);
	for i:=1 to n-1 do
	  for j:=1 to n do
	    begin
		  read(x,y); a[x,y]:=i;
		end;
	fillchar(visit,sizeof(visit),false);
	for i:=1 to n do
	  for j:=1 to n do
	    begin
		  if visit[i,j] then continue else x:=0;
		  fill(i,j); if x<>n then
		    begin
			  good:=false;
			  goto answer;
			end;
		end;
	answer:
	if good then writeln('good')
	  else writeln('wrong');
  until false;
end.
