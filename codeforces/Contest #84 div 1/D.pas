var
  n,i,j,ll,ans:longint;
  a,ind,pos,cur,s:array[0..200000] of longint;
  sp:array[0..400000,1..2] of longint;

procedure swap(var a,b:longint);
  var
    temp:longint;
	
  begin
    temp:=a; a:=b; b:=temp;
  end;

procedure sort(l,r:longint);
  var
    i,j,mid:longint;
  
  begin
    i:=l; j:=r; mid:=s[(l+r) div 2]; //mid:=s[random(r-l+1)+l];
	repeat
	  while s[i]<mid do inc(i);
	  while s[j]>mid do dec(j);
	  if i>j then break else swap(s[i],s[j]); swap(ind[i],ind[j]);
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

function lucky(a:longint):boolean;
  var
    temp:longint;
  
  begin
    temp:=a;
	while temp>0 do
	  if not ((temp mod 10=4)or(temp mod 10=7)) then exit(false)
		else temp:=temp div 10;
	exit(true);
  end;

begin
  randomize;
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do ind[i]:=i;
  for i:=1 to n do pos[i]:=i;
  for i:=1 to n do cur[i]:=i;
  s:=a; sort(1,n); ll:=-1;
  for i:=1 to n do
    if lucky(a[i]) then
	  begin
	    ll:=i; break;
	  end;
  if ll<0 then
    begin
	  for i:=1 to n-1 do
	    if a[i]>a[i+1] then
		  begin
		    writeln(-1); halt;
		  end;
	  writeln(0); halt;
	end;
  ans:=0;
  for i:=1 to n do
    begin
	  if pos[ind[i]]=i then continue;
	  if ll<>i then
	    begin
	      inc(ans); sp[ans][1]:=ll; sp[ans][2]:=i;
		end;
	  swap(pos[cur[i]],pos[cur[ll]]); swap(cur[i],cur[ll]);
	  {
	  writeln(ll);
	  for j:=1 to n do write(cur[j],' ');writeln;
	  for j:=1 to n do write(pos[j],' ');writeln;
	  writeln;
	  }
	  ll:=pos[ind[i]];
	  if i<>pos[ind[i]] then
	    begin
		  inc(ans); sp[ans][1]:=i; sp[ans][2]:=pos[ind[i]];
		end;
	  cur[pos[ind[i]]]:=cur[i];
	  pos[cur[i]]:=pos[ind[i]];
	end;
  writeln(ans);
  for i:=1 to ans do writeln(sp[i][1],' ',sp[i][2]);
end.
