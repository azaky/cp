uses math;

var
  n,i,j:longint;
  s,d:array[0..100001] of longint;
  dp:array[0..1000001] of longint;

procedure sort(l,r:longint);
  var
    i,j,mid,temp:longint;
  
  begin
    i := l; j := r; mid := d[random(r-l+1)+l];
    repeat
      while d[i]<mid do inc(i);
      while d[j]>mid do dec(j);
      if i>j then break;
      temp := d[i]; d[i] := d[j]; d[j] := temp;
      temp := s[i]; s[i] := s[j]; s[j] := temp;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;
  
begin
  readln(N);
  for i:=1 to n do readln(s[i],d[i]);
  for i:=1 to n do d[i] := s[i]+d[i];
  randomize; sort(1,n);
  for i:=1 to n do
    begin
      if d[i]>d[i-1] then
        for j:=d[i-1]+1 to d[i] do dp[j]:=dp[j-1];
      dp[d[i]] := max(dp[d[i]],1+dp[s[i]]);
    end;
  writeln(dp[d[n]]);
end.
