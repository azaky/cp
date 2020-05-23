uses math;

var
  n,k,l,i,j,ans:longint;
  a,temp:array[0..1000] of longint;
  finish:boolean;
  f:text;

function phi(n:longint):longint;
  var
    p,limit:longint;

  begin
    p:=2; phi:=n; limit:=trunc(sqrt(n));
    while n>1 do
      begin
        while (n mod p <> 0) and (p<=limit) do inc(p);
		if p>limit then
		  begin
		    phi:=phi*(n-1) div n;
			exit(phi);
		  end;
        phi:=(phi*(p-1)) div p;
        while n mod p = 0 do n:=n div p;
      end;
  end;

function power(a,b,c:int64):int64;
  
begin
  assign(f,'text.txt'); rewrite(f);
  readln(n,k); l:=n div k;
  for i:=1 to n do a[i]:=i;
  for i:=1 to n do write(f,i:5);writeln(f);
  repeat
      inc(ans);
	  for i:=0 to l-1 do
	    for j:=1 to k do
		  temp[i*k+j]:=a[n-j*l+i+1];
	  a:=temp;
	  for i:=1 to n do write(f,a[i]:5);writeln(f);
	  finish:=true;
	  for i:=1 to n do
	    if a[i]<>i then finish:=false;
  until finish;
  writeln(ans);
  ans:=0; l:=1;
  repeat
    inc(ans); l:=(k*l) mod (n+1);
  until l=1;
  writeln(ans);
  
  p:=phi(n+1); tau:=0;
  for i:=1 to trunc(sqrt(p))+1 do
    if p mod i=0 then
	  begin
	    inc(tau); d[tau]:=int64(i);
		if i*i=p then continue
		  else inc(tau); d[tau]:=int64(p div i);
	  end;
  
  ans:=p;
  for i:=1 to tau do
    if power(int64(k),d[i],int64(n+1))=1 then ans:=min(ans,d[i]);
	
  writeln(ans);
  
  close(f);
end.
