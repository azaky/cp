{
ID: a_zaky01
PROG: rectbarn
LANG: PASCAL
}

Var
	r,c,p,i,r0,c0,ans:longint;
	obs:array[0..3001,0..3001] of boolean;
	a:array[0..3001] of longint;

Procedure process;
	Var
	  prev,next,Stack:array[0..3001] of longint;
	  nStack,i:longint;
	
	Begin
	  nStack:=0; Stack[nStack]:=0;
	  for i:=1 to r do
	    begin
	      while a[Stack[nStack]]>=a[i] do dec(nStack);
	      inc(nStack); Stack[nStack]:=i; prev[i]:=Stack[nStack-1];
	    end;
	  nStack:=0; Stack[nStack]:=r+1;
	  for i:=r downto 1 do
	    begin
	      while a[Stack[nStack]]>=a[i] do dec(nStack);
	      inc(nStack); Stack[nStack]:=i; next[i]:=Stack[nStack-1];
	    end;
	  for i:=1 to r do
	    if a[i]*(next[i]-prev[i]-1)>ans then ans:=a[i]*(next[i]-prev[i]-1);
	End;

Begin
    Assign(input, 'rectbarn.in'); Reset(input);
    Assign(output, 'rectbarn.out'); Rewrite(output);
	readln(r,c,p);
	for i:=1 to p do
	  begin
	    readln(r0,c0); obs[r0][c0]:=true;
	  end;
	a[0]:=-1; a[r+1]:=-1;
	for c0:=1 to c do
	  begin
	    for r0:=1 to r do
	      if obs[r0][c0] then a[r0]:=0
	        else a[r0]:=a[r0]+1;
	    process;
	  end;
	writeln(ans);
    Close(input); Close(output);
End.
