var
  n,t,i,sum,j,a,b,mid,temp:longint;
  yes:boolean;
  num:array[0..8001] of longint;

procedure sort(l,r:longint);
  var
    i,j,temp,mid:longint;

  begin
    i:=l; j:=r; mid:=num[(l+r) div 2];
	repeat
	  while num[i]<mid do inc(i);
	  while num[j]>mid do dec(j);
	  if i>j then break else temp:=num[i]; num[i]:=num[j]; num[j]:=temp;
	  inc(i); dec(j);
	until false;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

begin
  readln(n,t);
  for i:=1 to n do readln(num[i]); sort(1,n);
  for i:=1 to t do
    begin
	  readln(sum); yes:=false;
	  for j:=1 to n do
	    begin
		  temp:=sum-num[j];
		  if (temp<num[1]) or (temp>num[n]) then continue;
		  a:=1; b:=n;
		  repeat
		    mid:=(a+b) div 2;
			if (b-a=1) and (temp<>num[a]) and (temp<>num[b]) then break;
			if temp=num[mid] then
			  begin
			    yes:=(mid<>j) or (num[mid-1]=temp) or (num[mid+1]=temp); break;
			  end
			else if num[mid]<temp then a:=mid+1
			  else b:=mid;
		  until false;
		  if yes then break;
		end;
	  if yes then writeln('YA')
	    else writeln('TIDAK');
	end;
end.