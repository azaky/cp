var
  n,kasus,step:longint;
  p:int64;

function palindrome(a:int64):boolean;
  var
    k,i:longint;
	p:array[0..11] of int64;
  
  begin
    k:=0;
	while a>0 do
	  begin
	    inc(k); p[k]:=a mod 10; a:=a div 10;
	  end;
    for i:=1 to k div 2 do
	  if p[i]<>p[k+1-i] then exit(false);
	exit(true);
  end;

function concat(a:int64):int64;
  var
    k,i:longint;
	p:array[0..11] of int64;
  
  begin
    k:=0;
	while a>0 do
	  begin
	    inc(k); p[k]:=a mod 10; a:=a div 10;
	  end;
	concat:=0;
	for i:=1 to k do concat:=concat*10+p[i];
  end;

begin
  readln(n);
  for kasus:=1 to n do
  begin
    readln(p);
	step:=0;
	while true do
	  begin
	    inc(step);
		p:=p+concat(p);
		if palindrome(p) then break;
	  end;
	writeln(step,' ',p);
  end;
end.
