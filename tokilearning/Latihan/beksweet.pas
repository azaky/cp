var
  n,i:longint;
  a,b,mid,havel,bring,have,ans:int64;
  p,s,ss:array[0..100001] of int64;

procedure sort(l,r:longint);
  var
    i,j:longint;
	mid,temp:int64;
  
  begin
    i:=l; j:=r; mid:=p[(l+r) div 2];
	repeat
	  while p[i]<mid do inc(i);
	  while p[j]>mid do dec(j);
	  if i>j then break else temp:=p[i]; p[i]:=p[j]; p[j]:=temp;
	  temp:=s[i]; s[i]:=s[j]; s[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

begin
  readln(n); a:=round(1e12); b:=0;
  for i:=1 to n do
    begin
	  readln(p[i],s[i]);
	  if s[i]<a then a:=s[i];
	  if s[i]>b then b:=s[i];
	end;
  sort(1,n); ans:=a;
  repeat
    mid:=(a+b) div 2;
	ss:=s;
	if ss[1]<mid then havel:=ss[1]-mid else havel:=0;
	if ss[1]>=mid then bring:=ss[1]-mid else bring:=0;
	for i:=2 to n do
	  begin
	    dec(bring,p[i]-p[i-1]); if bring<0 then bring:=0;
	    if havel<0 then dec(havel,p[i]-p[i-1]);
		ss[i]:=ss[i]+bring; bring:=0;
		if ss[i]<=mid then
		  begin
		    dec(havel,mid-ss[i]);
			continue;
		  end
		else have:=ss[i]-mid;
		if have+havel>=0 then
		  begin
		    have:=have+havel;
			bring:=have;
			havel:=0;
		  end
		else havel:=havel+have;
	  end;
	if havel<0 then b:=mid
	  else
	    begin
		  if mid>ans then ans:=mid;
		  a:=mid+1;
		end;
  until a>=b;
  writeln(ans);
end.
