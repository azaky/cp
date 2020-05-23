var
  n,i,start:longint;
  a,b:array[1..100000] of longint;
  ans:int64;

procedure reverse(l,r:longint);
  var
    i,temp:longint;
  
  begin
    for i:=l to (l+r) div 2 do
      begin
        temp:=a[i]; a[i]:=a[l+r-i]; a[l+r-i]:=temp;
      end;
    if l<r then inc(ans);
  end;

procedure sort(l,r:longint);
	var
		mid,il,ir,i:longint;
	
	begin
		if l=r then exit else mid:=(l+r) div 2;
		sort(l,mid); sort(mid+1,r);
		il:=l; ir:=mid+1;
		for i:=l to r do
			if (il<=mid) and (a[il]<=a[ir]) or (ir>r) then
				begin
					b[i]:=a[il]; inc(il);
				end
			else
				begin
					b[i]:=a[ir]; inc(ir); ans:=ans + int64(mid+1-il);
				end;
		for i:=l to r do a[i]:=b[i];
	end;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  //reverse one time
  start:=1;
  for i:=2 to n do
    if a[i]>a[i-1] then
      begin
        reverse(start,i-1);
        start:=i;
      end;
  reverse(start,n);
  //do bubble swap
  sort(1,n);
  writeln(ans);
end.
