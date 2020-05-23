const
  modd=1000000009;

var

procedure sort(l,r:longint);
  var
    i,j:longint;
	mid,temp:array[1..2] of longint;
  
  begin
    i:=l; j:=r; mid:=pair[(l+r) div 2];
	repeat
	  while (pair[i][1]<mid[1]) or ((pair[i][1]=mid[1]) and (pair[i][2]<mid[2])) do inc(i);
	  while (pair[j][1]>mid[1]) or ((pair[j][1]=mid[1]) and (pair[j][2]>mid[2])) do dec(j);
	  if i>j then break;
	  temp:=pair[i]; pair[i]:=pair[j]; pair[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

function find(x,y:longint):longint;
  var
    a,b,mid:longint;
  
  begin
    a:=1; b:=mm;
	while true do
	  begin
	    mid:=(a+b) div 2;
		if (pair[mid][1]=x) and (pair[mid][2]=y) then exit(mid);
		if a>b then exit(-1);
		if (pair[mid][1]<x) or ((pair[mid[1]=x) and (pair[mid][2]<y)) then b:=mid
		  else a:=mid+1;
	  end;
  end;

begin
  readln(n,m);
  for i:=1 to m do readln(ep1[i],ep2[i]);
  for i:=1 to m do
    begin
	  pair[i][1]:=ep1[i];
	  pair[i][2]:=ep2[i];
	end;
  sort(1,m);
  mm:=0;
  for i:=2 to m do
    if (pair[i][1]<>pair[i-1][1]) or (pair[i][2]<>pair[i-1][2]) then
	  begin
	    inc(mm);
		pair[mm][1]:=pair[i][1]; pair[mm][2]:=pair[i][2];
	  end;
  
end.
