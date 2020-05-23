var
  n,m:int64;
  dp:array[0..101,0..101] of int64;

function c(a,b:int64):int64;
  begin
    if dp[a,b]>0 then exit(dp[a,b]);
	if a=0 then dp[a,b]:=1
	  else if b=0 then dp[a,b]:=1
	    else dp[a,b]:=c(a-1,b)+c(a,b-1);
	dp[b,a]:=dp[a,b]; exit(dp[a,b]);
  end;

begin
  repeat
    readln(n,m); if n+m=0 then break;
	writeln(n,' things taken ',m,' at a time is ',C(n-m,m),' exactly.');
  until false;
end.
//00:05:20.627