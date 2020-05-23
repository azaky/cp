var
  n,i:longint;
  s:array[1..10000] of string;

procedure sort(l,r:longint);
  var
    i,j,p,midl:longint;
	mids,temp:string;
  
  begin
    i:=l; j:=r; p:=random(r-l+1)+l; mids:=s[p]; midl:=length(s[p]);
	repeat
	  while (length(s[i])<midl) or ((length(s[i])=midl) and (s[i]<mids)) do inc(i);
	  while (length(s[j])>midl) or ((length(s[j])=midl) and (s[j]>mids)) do dec(j);
	  if i>j then break else temp:=s[i]; s[i]:=s[j]; s[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

begin
  readln(n); randomize;
  for i:=1 to n do readln(s[i]);
  sort(1,n);
  for i:=1 to n do writeln(s[i]);
end.
