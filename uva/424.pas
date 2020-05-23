type
  bignum=array[0..200] of longint;

var
  tot,sum,temp:bignum;
  s:ansistring;
  i,borrow:longint;

begin
  fillchar(tot,sizeof(tot),0);
  repeat
    readln(s); if s='0' then break;
	fillchar(temp,sizeof(temp),0);
	for i:=1 to length(s) do temp[i-1]:=ord(s[1+length(s)-i])-ord('0');
	borrow:=0;
	for i:=0 to 200 do
	  begin
	    sum[i]:=temp[i]+tot[i]+borrow;
		borrow:=sum[i] div 10; sum[i]:=sum[i] mod 10;
	  end;
	tot:=sum;
  until false;
  for i:=200 downto 0 do
    if tot[i]>0 then break;
  for i:=i downto 0 do write(tot[i]);writeln;
end.
//00:06:13.30