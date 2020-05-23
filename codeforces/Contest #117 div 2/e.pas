uses math;

const maxx = 1000000007;

var
  n,l,ll,i,j:longint;
  ans:int64;
  a,b:array[0..111] of longint;
  board:array[0..111,0..111] of longint;
  dp:array[0..3333,0..111,1..2] of int64;

function power(a,b:longint):int64;
  var temp:int64;
  begin
    if b=0 then exit(1) else temp:=power(a,b div 2);
    temp:=(temp*temp) mod maxx;
    if b mod 2=1 then temp:=(temp*int64(a)) mod maxx;
    exit(temp);
  end;

begin
  readln(n,l);
  for i:=1 to n do readln(a[i],b[i]);
  for i:=1 to n do
    begin
      dp[a[i]][i][1]:=1; dp[b[i]][i][2]:=1;
    end;
  for ll:=1 to l do
    for i:=1 to n do
      for j:=1 to n do
        if i<>j then
          begin
            if (a[j]=a[i]) and (ll>=a[i]) then dp[ll][i][1]:=(dp[ll][i][1]+dp[ll-a[i]][j][2]) mod maxx;
            if (b[j]=a[i]) and (ll>=a[i]) and (a[j]<>b[j]) then dp[ll][i][1]:=(dp[ll][i][1]+dp[ll-a[i]][j][1]) mod maxx;
            if (a[j]=b[i]) and (ll>=b[i]) then dp[ll][i][2]:=(dp[ll][i][2]+dp[ll-b[i]][j][2]) mod maxx;
            if (b[j]=b[i]) and (ll>=b[i]) and (a[j]<>b[j]) then dp[ll][i][2]:=(dp[ll][i][2]+dp[ll-b[i]][j][1]) mod maxx;
          end;

  for i:=1 to l do
    begin
      for j:=1 to n do write(dp[i][j][1]:4);writeln;
    end;

   writeln('-------');
  for i:=1 to l do
    begin
      for j:=1 to n do write(dp[i][j][2]:4);writeln;
    end;

  //count the double counting
  for i:=1 to n do inc(board[min(a[i],b[i])][max(a[i],b[i])]);
  for i:=1 to 100 do
    for j:=i to 100 do
      if (i<>j) and (board[i][j]>1) then
        begin
          if l mod (i+j)=0 then ans:=(ans+board[i][j]*power(board[i][j]-1,2*(l div (i+j))-1)) mod maxx;
        end;
  for i:=1 to 100 do
    if board[i][i]>0 then
      begin
        if l mod i=0 then ans:=(ans+board[i][i]*power(board[i][i]-1,(l div i)-1)) mod maxx;
      end;
  ans:=-ans;
  writeln(ans);
  ans:=(ans+maxx) mod maxx;
  for i:=1 to n do
    ans:=(ans+dp[l][i][1]+dp[l][i][2]) mod maxx;
  writeln(ans);
end.
