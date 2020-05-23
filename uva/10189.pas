var
  n,m,i,j,i1,j1,x,kasus:longint;
  board:array[0..101,0..101] of char;

begin
  repeat
    readln(n,m); inc(kasus); 
	if n+m=0 then break else fillchar(board,sizeof(board),'.');
	if kasus>1 then writeln;
	writeln('Field #',kasus,':');
	for i:=1 to n do
	  begin
	    for j:=1 to m do read(board[i,j]);
		readln;
	  end;
	for i:=1 to n do
	  for j:=1 to m do
	    begin
		  if board[i,j]='*' then
		    begin
			  write('*'); if j=m then writeln;
			  continue;
			end
		  else x:=0;
		  for i1:=i-1 to i+1 do
		    for j1:=j-1 to j+1 do
			  if board[i1,j1]='*' then inc(x);
		  write(x); if j=m then writeln;
		end;
  until false;
end.
