{
ID: a_zaky01
PROG: baleshare
LANG: PASCAL
}

type
  bale = array[1..3] of integer;

Var
  n,i,best,j,temp:integer;
  b:bale;
  a:array[0..22] of integer;
  
procedure pick(k,high:integer; b:bale);
  var
    i:integer;
	
  begin
    if k>n then
	  begin
		if high<best then best:=high;
		exit;
	  end;
	if high>best then exit;
	for i:=1 to 3 do
	  begin
	    b[i]:=b[i]+a[k];
		if b[i]>high then pick(k+1,b[i],b)
		  else pick(k+1,high,b);
		b[i]:=b[i]-a[k];
	  end;
  end;
  
Begin
    Assign(input, 'baleshare.in'); Reset(input);
    Assign(output, 'baleshare.out'); Rewrite(output);
	readln(n);
	for i:=1 to n do readln(a[i]);
	for i:=1 to n-1 do
	  for j:=n downto i+1 do
	    if a[j]>a[j-1] then
		  begin
		    temp:=a[j]; a[j]:=a[j-1]; a[j-1]:=temp;
		  end;
	best:=0;
	for i:=1 to (n+2) div 3 do best:=best+a[i];
	pick(1,0,b);
	writeln(best);
    Close(input); Close(output);
End.
