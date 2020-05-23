var
  tc,kasus,m,n,nans,i,lim,maxb,ti,best,p:longint;
  a,b,ans:array[0..100001] of longint;

procedure sort(l,r:longint);
  var
    i,j,mida,midb,temp:longint;
  
  begin
    i:=l; j:=r; mida:=a[(l+r) div 2]; midb:=b[(l+r) div 2];
	repeat
	  while (a[i]<mida) or ((a[i]=mida) and (b[i]<midb)) do inc(i);
	  while (a[j]>mida) or ((a[j]=mida) and (b[j]>midb)) do dec(j);
	  if i>j then break;
	  temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
	  temp:=b[i]; b[i]:=b[j]; b[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

begin
  readln(tc); readln;
  for kasus:=1 to tc do
    begin
	  readln(m); n:=0; nans:=0;
	  repeat
	    inc(n); readln(a[n],b[n]);
	  until (a[n]=0) and (b[n]=0);
	  dec(n); sort(1,n);

	  //for i:=1 to n do writeln(i,':',a[i],' ',b[i]);
	  p:=1;
	  while (p<=n) and (b[p]<0) do inc(p);
	  if (a[p]>0) or (p>n) then
	    begin
		  writeln(0);
		  if kasus<tc then writeln;
		  continue;
		end;
	  lim:=0;
	  while true do
	    begin
		  if (a[p]>lim) or (p>n) then
		    begin
			  writeln(0);
			  if kasus<tc then writeln;
			  break;
			end;
		  best:=p; inc(p);
		  while (p<=n) and (a[p]<=lim) do
		    begin
			  if b[p]>b[best] then best:=p;
			  inc(p);
			end;
		  inc(nans); ans[nans]:=best;
		  lim:=b[best]; {writeln(lim,' ',best,' ',p);}
		  if lim>=m then
		    begin
			  writeln(nans);
			  for i:=1 to nans do writeln(a[ans[i]],' ',b[ans[i]]);
			  if kasus<tc then writeln;
			  break;
			end;
		end;

{
      lim:=0; maxb:=0; ti:=-1;
	  for i:=1 to n do
	    begin
		  if b[i]<lim then continue;
		  if a[i]>lim then
		    begin
			  if (ti=-1) or ((a[i]>maxb) and (maxb<m)) then break;
			  inc(nans); ans[nans]:=ti;
			  lim:=b[i]; maxb:=b[i];
			  if b[i]>=m then break;
			end;
		  if (b[i]>maxb) and (a[i]<=lim) then
		    begin
			  ti:=i; maxb:=b[i];
			end;
		end;
	  if (b[nans]<m) and (ti<>-1) then
	    begin
		  inc(nans); ans[nans]:=ti;
		end;
	  if (nans=0) or (maxb<m) then writeln(0)
	    else
		  begin
		    writeln(nans);
			for i:=1 to nans do writeln(a[ans[i]],' ',b[ans[i]]);
		  end;
	  if kasus<tc then writeln;
}
	end;
end.
