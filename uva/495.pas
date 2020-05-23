const
  maxnum = 1000000000000000;
  maxlen = 70;
  baslen = 15;

type
  bignum = array[-1..maxlen] of int64;

var
  i,n:longint;
  null:array[0..15] of string;
  f:array[0..5000] of bignum;

function sum(n1,n2:bignum):bignum;
  var
    borrow,temp:int64;
	p1,p2,i:longint;
  
  begin
    fillchar(sum,sizeof(sum),0); borrow:=0;
	p1:=maxlen; p2:=p1;
	while (p1>=0) and (n1[p1]=0) do dec(p1); if p1<0 then exit(n2);
	while (p2>=0) and (n2[p2]=0) do dec(p2); if p2<0 then exit(n1);
	for i:=0 to maxlen do
	  begin
	    temp:=n1[i]+n2[i]+borrow; sum[i]:=temp mod maxnum; borrow:=temp div maxnum;
		if (borrow=0) and (i>p1) and (i>p2) then break;
	  end;
  end;

procedure println(n:bignum);
  var
    p,i:longint;
  
  begin
    p:=maxlen; while (p>=0) and (n[p]=0) do dec(p);
	if p<0 then
	  begin
	    writeln(0); exit;
	  end;
	write(n[p]); dec(p);
	for i:=p downto 0 do
	  begin
	    if n[i]=0 then
		  begin
		    write(null[baslen]); continue;
		  end
		else write(null[baslen-trunc(ln(n[i])/ln(10))-1]); write(n[i]);
	  end;
	writeln;
  end;

begin
  null[0]:=''; for i:=1 to baslen do null[i]:=null[i-1]+'0';
  f[1][0]:=1;
  for i:=2 to 5000 do f[i]:=sum(f[i-1],f[i-2]);
  repeat
    readln(n); write('The Fibonacci number for ',n,' is '); println(f[n]);
  until eof;
end.
