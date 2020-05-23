var
  s:string;
  n,num,i,ans:longint;
  a:array[1..13] of int64;
  t:array[0..1594323] of int64;

procedure create(pos:longint; sum,cur:int64; change:boolean);
  begin
    //writeln(pos:5,' ',sum:5,' ',cur:5,' ',change:5);
    if pos=n then
	  begin
	    inc(num); t[num]:=sum+cur;
		if (cur<>0) and change then
		  begin
		    inc(num); t[num]:=sum-cur;
		  end;
		exit;
	  end else inc(pos);
	create(pos,sum+cur,a[pos],true);
	if (cur<>0) and change then create(pos,sum-cur,a[pos],true);
	create(pos,sum,10*cur+a[pos],change);
  end;

procedure sort(l,r:longint);
  var
    i,j:longint;
	mid,temp:int64;
  
  begin
    i:=l; j:=r; mid:=t[(l+r) div 2];
	repeat
	  while t[i]<mid do inc(i);
	  while t[j]>mid do dec(j);
	  if i>j then break else temp:=t[i]; t[i]:=t[j]; t[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

begin
  readln(s); n:=length(s); num:=0; t[0]:=-1000000000000000;
  for i:=1 to n do a[i]:=ord(s[i])-ord('0');
  create(1,0,a[1],false); sort(1,num); ans:=0;
  for i:=1 to num do
    if t[i]<>t[i-1] then inc(ans);
  writeln(ans);
end.
