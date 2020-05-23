var
  n,i:longint;
  dp,vis:array[0..1111111] of boolean;

function prime(x:longint):boolean;
  var
    i:longint;
  
  begin
    if (x=1) then exit(false);
    if (x<4) then exit(true);
    for i:=2 to trunc(sqrt(x)) do
      if x mod i = 0 then exit(false);
    exit(true);
  end;

function win(n:longint):boolean;
  var
    i:longint;
  
  begin
    if vis[n] then exit(dp[n]);
    vis[n] := true;
    if prime(n) then
      begin
        dp[n] := true;
        exit(dp[n]);
      end;
    dp[n] := false;
    if not win(n+1) then dp[n] := true;
    for i:=2 to n-1 do
      if n mod i = 0 then
        if prime(i) then
          if not win(n div i) then dp[n] := true;
    exit(dp[n]);
  end;

begin
  for n:=2 to 100 do
    if not win(n) then writeln(n);
  while true do
    begin
      readln(n);
      writeln(win(n));
    end;
end.
