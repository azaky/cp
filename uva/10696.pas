var
  n:int64;
  dp:array[0..100] of int64;

function f(n:int64):int64;
  begin
    if n>=101 then exit(n-10)
	  else if dp[n]>=0 then exit(dp[n]);
	dp[n]:=f(f(n+11)); exit(dp[n]);
  end;

begin
  fillchar(dp,sizeof(dp),255);
  repeat
    readln(n); if n=0 then break;
	writeln('f91(',n,') = ',f(n));
  until false;
end.
//00:04:13.620