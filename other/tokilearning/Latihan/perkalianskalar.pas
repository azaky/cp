type
  arr = array[1..10000] of int64;

var
  n,i:longint;
  ans:int64;
  v1,v2:arr;

procedure qsort(var a:arr);
  procedure sort(l,r:longint);
    var
	  i,j:longint;
	  mid,temp:int64;
	
	begin
	  i:=l; j:=r; mid:=a[random(r-l+1)+l];
	  repeat
	    while a[i]<mid do inc(i);
		while a[j]>mid do dec(j);
		if i>j then break else temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
		inc(i); dec(j);
       until i>j;
	   if l<j then sort(l,j);
	   if i<r then sort(i,r);
	end;
  
  begin
    sort(1,n);
  end;

begin
  readln(n); randomize;
  for i:=1 to n do read(v1[i]);
  for i:=1 to n do read(v2[i]);
  qsort(v1); qsort(v2); ans:=0;
  for i:=1 to n do ans:=ans+v1[i]*v2[n+1-i];
  writeln(ans);
end.
