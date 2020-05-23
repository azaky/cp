var
  n,q,i,a,b,mid:longint;
  ch:char;
  name,phone:array[0..10001] of string;

procedure sort(l,r:longint);
  var
    i,j:longint;
	temp,mid:string;
  
  begin
    i:=l; j:=r; mid:=name[(l+r) div 2];
	repeat
	  while name[i]<mid do inc(i);
	  while name[j]>mid do dec(j);
	  if i>j then break else temp:=name[i]; name[i]:=name[j]; name[j]:=temp;
	  temp:=phone[i]; phone[i]:=phone[j]; phone[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;

begin
  readln(n,q);
  for i:=1 to n do
    begin
	  read(ch); name[i]:='';
	  while ch<>' ' do
	    begin
		  name[i]:=name[i]+ch;
		  read(ch);
		end;
	  readln(phone[i]);
	end;
  sort(1,n);
  for i:=1 to q do
    begin
	  readln(name[0]);
	  a:=1; b:=n;
	  repeat
	    mid:=(a+b) div 2;
		if name[mid]=name[0] then
		  begin
		    writeln(phone[mid]);
			break;
		  end
		else if name[mid]<name[0] then a:=mid+1
		  else b:=mid;
	  until false;
	end;
end.
