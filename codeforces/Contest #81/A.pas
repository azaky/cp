var
  n,m,i,j,k,ans,c:longint;
  ch:char;
  _k:extended;
  s:string;
  level:array[1..100] of longint;
  sk:array[1..100] of string;

procedure sort(l,r:longint);
  var
    i,j,tem:longint;
	mid,temp:string;
  
  begin
    i:=l; j:=r; mid:=sk[(l+r) div 2];
	repeat
	  while sk[i]<mid do inc(i);
	  while sk[j]>mid do dec(j);
	  if i>j then break else temp:=sk[i]; sk[i]:=sk[j]; sk[j]:=temp;
	  tem:=level[i]; level[i]:=level[j]; level[j]:=tem;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

begin
  readln(n,m,_k);
  k:=round(_k*100);
  i:=0; c:=0;
  repeat
    inc(i); inc(c);
	sk[i]:='';
	repeat
	  read(ch);
	until ch in ['a'..'z'];
	repeat
	  sk[i]:=sk[i]+ch;
	  read(ch);
	until not (ch in ['a'..'z']);
	readln(level[i]); level[i]:=level[i]*k div 100;
	if level[i]<100 then dec(i);
  until c=n;
  n:=i; ans:=n;
  for i:=1 to m do
    begin
	  readln(s);
	  for j:=1 to n+1 do
	    if sk[j]=s then break;
	  if j>n then
	    begin
		  inc(n); inc(ans); sk[n]:=s; level[n]:=100000;
		end;
	end;
  sort(1,n);
  writeln(ans);
  for i:=1 to n do
    if level[i]<100 then continue
	  else if level[i]=100000 then writeln(sk[i],' 0')
	    else writeln(sk[i],' ',level[i]);
  writeln(3250*0.26:0:22);
  writeln(trunc(3250*0.26));
  writeln(trunc(3250*26/100));
  writeln(3250*26 div 100);
end.
