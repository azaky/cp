var
  tc,kasus,n,m,l,i,a,b,t:longint;
  ch:char;
  agen:array[1..100] of string;
  cost:array[1..100] of longint;

procedure sort(l,r:longint);
  var
    i,j,midc,tempc:longint;
	mida,tempa:string;
  
  begin
    i:=l; j:=r; mida:=agen[(l+r) div 2]; midc:=cost[(l+r) div 2];
	repeat
	  while (cost[i]<midc) or ((cost[i]=midc) and (agen[i]<mida)) do inc(i);
	  while (cost[j]>midc) or ((cost[j]=midc) and (agen[j]>mida)) do dec(j);
	  if i>j then break else tempa:=agen[i]; agen[i]:=agen[j]; agen[j]:=tempa;
	  tempc:=cost[i]; cost[i]:=cost[j]; cost[j]:=tempc; inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

begin
  readln(tc);
  for kasus:=1 to tc do
    begin
	  readln(n,m,l);
	  for i:=1 to l do
	    begin
		  agen[i]:='';
		  repeat
		    read(ch);
			if ch=':' then break else agen[i]:=agen[i]+ch;
		  until false;
		  a:=0;
		  repeat
		    read(ch);
			if ch=',' then break else a:=10*a+ord(ch)-ord('0');
		  until false; readln(b);
		  t:=n; cost[i]:=0;
		  repeat
		    if ((t div 2)>=m) and ((t-(t div 2))*a>b) then
			  begin
			    t:=t div 2; cost[i]:=cost[i]+b;
			  end
			else
			  begin
			    cost[i]:=cost[i]+a*(t-m); break;
			  end;
		  until t=m;
		end;
	  sort(1,l);
	  writeln('Case ',kasus);
	  for i:=1 to l do writeln(agen[i],' ',cost[i]);
	end;
end.