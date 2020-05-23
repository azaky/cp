var
  tc,kasus,m,k,i,j,p:longint;
  l,r,t,mid:int64;
  a,sum:array[0..501] of int64;
  pos:array[0..501] of longint;

function check(s:int64; st,k:longint):boolean;
  var
    p,i:longint;
	t:int64;
  
  begin
    check:=true;
	p:=1; t:=0;
    for i:=st to m do
	  if a[i]>s then exit(false)
	    else if t+a[i]<=s then t:=t+a[i]
	      else
		    begin
		      inc(p); t:=a[i];
		    end;
    exit(p<=k);
  end;

begin
  readln(tc);
  for kasus:=1 to tc do
    begin
	  readln(m,k);
	  for i:=1 to m do read(a[i]);
	  for i:=1 to m do sum[i]:=sum[i-1]+a[i]; r:=sum[m];
	  l:=10000001; for i:=1 to m do if a[i]<l then l:=a[i];
	  while l<r do
	    begin
		  mid:=(l+r) div 2;
		  if check(mid,1,k) then r:=mid
		    else l:=mid+1;
		end;
	  p:=1;
	  for i:=1 to m do
	    begin
		  if i=1 then write(a[i]) else write(' ',a[i]);
		  if check(l,i+1,k-p) then
		    begin
			  inc(p);
			  write(' /');
			end;
		end;
	  writeln;
	  {
	  p:=1; t:=0;
	  for i:=1 to m do
	    if t+a[i]<=l then t:=t+a[i]
		  else
		    begin
			  pos[p]:=i-1; inc(p); t:=a[i];
			end;
	  pos[0]:=0; pos[p]:=m;
	  for i:=p downto 1 do
	    begin
		  for j:=pos[i] downto pos[i-1]+1 do
		    if j=m then write(a[j])
			  else write(' ',a[j]);
		  if i>1 then write(' /')
		    else writeln;
		end;
	  }
	end;
end.