var
  i,t,sum,best:longint;
  ans:string[3];
  b,c,g:array[1..3] of longint;

begin
  repeat
    for i:=1 to 3 do read(b[i],g[i],c[i]); readln; best:=maxlongint; sum:=0;
	for i:=1 to 3 do sum:=sum+b[i]+g[i]+c[i];
	{BCG} t:=sum-b[1]-c[2]-g[3];
	if t<best then
	  begin
	    best:=t; ans:='BCG';
	  end;
	{BGC} t:=sum-b[1]-g[2]-c[3];
	if t<best then
	  begin
	    best:=t; ans:='BGC';
	  end;
	{CBG} t:=sum-c[1]-b[2]-g[3];
	if t<best then
	  begin
	    best:=t; ans:='CBG';
	  end;
	{CGB} t:=sum-c[1]-g[2]-b[3];
	if t<best then
	  begin
	    best:=t; ans:='CGB';
	  end;
	{GBC} t:=sum-g[1]-b[2]-c[3];
	if t<best then
	  begin
	    best:=t; ans:='GBC';
	  end;
	{GCB} t:=sum-g[1]-c[2]-b[3];
	if t<best then
	  begin
	    best:=t; ans:='GCB';
	  end;
	writeln(ans,' ',best);
  until eof;
end.
