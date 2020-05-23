var
  s,a,b,t:ansistring;
  ls,la,lb,oa,ob,i,j,k,z,ans:longint;
  oc:boolean;
  pa,pb:array[1..2000] of longint;
  st:array[1..4000000] of ansistring;

procedure sort(l,r:longint);
  var
    i,j:longint;
	mid,temp:ansistring;
  
  begin
    i:=l; j:=r; mid:=st[random(r-l+1)+l];
	repeat
	  while st[i]<mid do inc(i);
	  while st[j]>mid do dec(j);
	  if i>j then break else temp:=st[i]; st[i]:=st[j]; st[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

begin
  readln(s);readln(a);readln(b);randomize;
  ls:=length(s);la:=length(a);lb:=length(b);
  oa:=0;ob:=0;
  if (ls<la) or (ls<lb) then
    begin
	  writeln(0);halt;
	end;
  for i:=0 to ls-la do
    begin
	  oc:=true;
	  for j:=1 to la do
	    if s[i+j]<>a[j] then
		  begin
		    oc:=false;break;
		  end;
	  if oc then
	    begin
		  inc(oa);pa[oa]:=i;
		end;
	end;
  for i:=0 to ls-lb do
    begin
	  oc:=true;
	  for j:=1 to lb do
	    if s[i+j]<>b[j] then
		  begin
		    oc:=false;break;
		  end;
	  if oc then
	    begin
		  inc(ob);pb[ob]:=i;
		end;
	end;
  if (oa=0) or (ob=0) then
    begin
	  writeln(0);halt;
	end;
  for i:=1 to oa do
    begin
	  t:=''; j:=1;
	  while (j<=ob) and not((pa[i]<=pb[j]) and (pb[j]+lb>=pa[i]+la)) do inc(j);
	  if j>ob then break;
	  for z:=pa[i]+1 to pb[j]+lb do t:=t+s[z];
	  inc(ans);st[ans]:=t;
	  for k:=j+1 to ob do
	    begin
		  for z:=pb[k-1]+1 to pb[k] do t:=t+s[z+lb];
		  inc(ans);st[ans]:=t;
		end;
	end;
  sort(1,ans);
  for i:=2 to ans do
    if st[i]=st[i-1] then dec(ans);
  writeln(ans);
end.
