var
  s:ansistring;
  t,n,i,j,max:longint;
  a:array[0..30] of longint;

procedure flip(k:longint);
  var
    i,temp:longint;
  
  begin
    for i:=k to (k+n) div 2 do
	  begin
	    temp:=a[i]; a[i]:=a[k+n-i]; a[k+n-i]:=temp;
	  end;
  end;

begin
  repeat
	readln(s); writeln(s);
	t:=0; n:=0;
	for i:=1 to length(s) do
      if s[i]=' ' then
		begin
		  inc(n); a[n]:=t; t:=0;
		end
	  else t:=10*t+ord(s[i])-ord('0');
	if s[length(s)]<>' ' then
	  begin
		inc(n); a[n]:=t;
      end;
	flip(1);
    for i:=1 to n do
	  begin
	    max:=0;
		for j:=i to n do
		  if a[j]>a[max] then max:=j;
		if max=i then continue;
		if max<>n then
		  begin
		    flip(max); write(max,' ');
		  end;
		flip(i); write(i,' ');
	  end;
	writeln(0);
  until eof;
end.
