var
  n,m:longint;
  f:array[0..41,0..41] of longint;

function dp(n,m:longint):longint;
  var
    dpt,temp,i:longint;
	
  begin
    if f[n,m]<>-1 then exit(f[n,m]);
	dpt:=0;
	for i:=1 to n div 2 do
	  begin
	    temp:=dp(i,m)+dp(n-i,m);
		if temp>dpt then dpt:=temp;
	  end;
	for i:=1 to m div 2 do
	  begin
	    temp:=dp(n,i)+dp(n,m-i);
		if temp>dpt then dpt:=temp;
	  end;
	f[n,m]:=dpt; f[m,n]:=dpt; exit(dpt);
  end;

begin
  readln(n,m);
  fillchar(f,sizeof(f),255);
  f[1,1]:=0; f[1,2]:=1; f[2,1]:=1; f[1,3]:=2; f[3,1]:=2;
  writeln(dp(n,m));
  {
  if (n=1) or (m=1) then
    begin
	  writeln((n*m) div 3);
	  halt;
	end;
  }
end.
