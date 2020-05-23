var
  ntc, itc, n : longint;
  s : ansistring;
  visit, dp : array[0..111,0..111] of boolean;

function balanced(l,r : longint): boolean;
  var
    i : longint;
  
  begin
    if (visit[l][r]) then exit(dp[l][r]) else visit[l][r] := true;
    dp[l][r] := false;
    if (l = r) then
      begin
        if (s[l] <> '(') and (s[l] <> ')') then dp[l][r] := true;
        exit(dp[l][r]);
      end;
    if (l > r) then
      begin
        dp[l][r] := true;
        exit(dp[l][r]);
      end;
    if (s[l] = '(') and (s[r] = ')') and balanced(l+1,r-1) then dp[l][r] := true;
    if (s[l] = ':') and ((s[l+1] = '(') or (s[l+1] = ')')) and balanced(l+2,r) then dp[l][r] := true;
    //if ((s[l] = '(') or (s[l] = ')')) and (s[l+1] = ':') and balanced(l+2,r) then dp[l][r] := true;
    for i := l to r-1 do if balanced(l,i) and balanced(i+1,r) then dp[l][r] := true;
    exit(dp[l][r]);
  end;

begin
  readln(ntc);
  for itc := 1 to ntc do
    begin
      readln(s); n := length(s);
      fillchar(visit,sizeof(visit),0);
      if (balanced(1,n)) then writeln('Case #',itc,': YES') else writeln('Case #',itc,': NO');
    end;
end.
