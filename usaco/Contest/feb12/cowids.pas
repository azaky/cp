{
ID: a_zaky01
PROG: cowids
LANG: PASCAL
}

const
  max = 11111111;

Var
  i,j,len,k,pos:longint;
  n,d,ans:longint;
  com:array[-1..1000,-1..1000] of longint;

Begin
    Assign(input, 'cowids.in'); Reset(input);
    Assign(output, 'cowids.out'); Rewrite(output);
	for i:=0 to 500 do begin com[i,0]:=1; com[0,i]:=1; end;
	for i:=1 to 500 do
	  for j:=1 to 500 do
	    if (com[i-1,j]<max) and (com[i,j-1]<max) then com[i,j]:=com[i-1,j]+com[i,j-1];
	readln(n,k);
	if k=1 then
	  begin
	    write(1);for i:=1 to n-1 do write(0);writeln;
	    close(input); close(output);
	    halt;
	  end;
	d:=1; len:=k;
	while d<n do
	  begin
	    inc(len);
	    if k=2 then inc(d,len-1) else inc(d,com[len-k,k-1]);
	  end;
	if k=2 then d:=d-(len-1) else d:=d-com[len-k,k-1];
	n:=n-d; d:=0; dec(k);
	write(1);
	if k=1 then
	  begin
	    for i:=1 to len-n-1 do write(0);
	    write(1);
	    for i:=1 to n-1 do write(0);
	    writeln;
	    close(input); close(output);
	    halt;
	  end;
	for pos:=len-1 downto 1 do
	  begin
	    d:=d+com[pos-k-1,k];
	    if d>=n then
	      begin
	        d:=d-com[pos-k-1,k];
	        write(0);
	      end
	    else
	      begin
	        write(1);
	        dec(k);
	      end;
	  end;
	writeln;
    Close(input); Close(output);
End.
