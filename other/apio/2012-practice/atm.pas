uses math;

const
  maxE = 1000005; maxV = 500005;

var
//Variables for SCC, to distinguish it from the others
  nscc,index,nStack:longint;
  idx,scc,stack,lowlink:array[0..maxV] of longint;
  inS:array[0..maxV] of boolean;
//Now, all other variables
  n,m,i,s,p,temp,ans,mscc:longint;
  ep1,ep2,z,zscc:array[0..maxE] of longint;
  deg,degscc,dp,w:array[0..maxV] of longint;
  visit,pub:array[0..maxV] of boolean;

procedure StrongConnect(v:longint);
  var
    w,i:longint;
  
  begin
    idx[v]:=index; lowlink[v]:=index; inc(index);
    inc(nStack); stack[nStack]:=v; inS[v]:=true;
    for i:=deg[v]+1 to deg[v+1] do
      begin
        w := z[i];
        if idx[w]<0 then
          begin
            StrongConnect(w);
            lowlink[v]:=min(lowlink[v],lowlink[w]);
          end
        else if inS[w] then lowlink[v]:=min(lowlink[v],idx[w]);
      end;
    if lowlink[v]=idx[v] then
      begin
        inc(nscc);
        repeat
          w:=stack[nStack]; dec(nStack); inS[w]:=false;
          scc[w]:=nscc;
        until w=v;
      end;
  end;

procedure sort(l,r:longint);
  var
    i,j,p,mid1,mid2,temp:longint;
  
  begin
    i:=l; j:=r; p:=random(r-l+1)+l; mid1:=ep1[p]; mid2:=ep2[p];
    repeat
      while (ep1[i]<mid1) or ((ep1[i]=mid1) and (ep2[i]<mid2)) do inc(i);
      while (ep1[j]>mid1) or ((ep1[j]=mid1) and (ep2[j]>mid2)) do dec(j);
      if i>j then break;
      temp:=ep1[i]; ep1[i]:=ep1[j]; ep1[j]:=temp;
      temp:=ep2[i]; ep2[i]:=ep2[j]; ep2[j]:=temp;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

function rob(v:longint):longint;
  var
    i:longint;
  
  begin
    if visit[v] then exit(dp[v]) else visit[v]:=true;
    for i:=degscc[v]+1 to degscc[v+1] do dp[v]:=max(dp[v],rob(zscc[i]));
//handling the case that current location is not reachable from s
    if dp[v]>0 then dp[v]:=dp[v]+w[v];
    exit(dp[v]);
  end;

begin
  randomize;
//initializing the graph
  readln(n,m);
  for i:=1 to m do
    begin
      readln(ep1[i],ep2[i]);
      inc(deg[ep1[i]]);
    end;
  for i:=1 to n+1 do deg[i]:=deg[i]+deg[i-1];
  for i:=1 to m do
    begin
      z[deg[ep1[i]]]:=ep2[i];
      dec(deg[ep1[i]]);
    end;
//creating Strongly Connected Components, Tarjan's algorithm
  fillchar(idx,sizeof(idx),255);
  for i:=1 to n do
    if idx[i]<0 then StrongConnect(i);
//output the result of SCC
{
writeln('SCC result----------------------------------------------');
  for i:=1 to n do writeln(idx[i]:3,lowlink[i]:3);
  for i:=1 to n do writeln(scc[i]);
writeln('--------------------------------------------------------');
}
//creating new graph based on this SCC
  //creating adjacency list
  for i:=1 to m do
    begin
      ep1[i]:=scc[ep1[i]]; ep2[i]:=scc[ep2[i]];
    end;
  //deleting double occurences of the edges
  sort(1,m); mscc:=0;
  for i:=1 to m do
    if not ((ep1[i]=ep1[i-1]) and (ep2[i]=ep2[i-1])) and (ep1[i]<>ep2[i]) then
      begin
        inc(mscc); ep1[mscc]:=ep1[i]; ep2[mscc]:=ep2[i];
      end;
  for i:=1 to mscc do inc(degscc[ep2[i]]);
  for i:=1 to nscc+1 do degscc[i]:=degscc[i]+degscc[i-1];
  for i:=1 to mscc do
    begin
      zscc[degscc[ep2[i]]]:=ep1[i];
      dec(degscc[ep2[i]]);
    end;
{
writeln('new edge list-------------------------------------------');
  writeln(mscc);
  for i:=1 to mscc do writeln(ep1[i]:3,ep2[i]:3);
  for i:=1 to nscc do write(degscc[i]:3);writeln;
  for i:=1 to degscc[nscc+1] do write(zscc[i]:3);writeln;
writeln('--------------------------------------------------------');
}
  //calculating weights
  for i:=1 to n do
    begin
      readln(temp);
      w[scc[i]]:=w[scc[i]]+temp;
    end;
{
writeln('the weights---------------------------------------------');
  for i:=1 to nscc do writeln(w[i]);
writeln('--------------------------------------------------------');
}
  //determining pubs' location
  readln(s,p);
  for i:=1 to p do
    begin
      read(temp); pub[scc[temp]]:=true;
    end;
//initializing dp values
  s:=scc[s]; dp[s]:=w[s]; visit[s]:=true;
  for i:=1 to nscc do dp[i]:=rob(i);
{
writeln('final dp values-----------------------------------------');
  writeln(s);
  for i:=1 to nscc do writeln(dp[i]);
writeln('--------------------------------------------------------');
}
//getting the answer
  ans:=0;
  for i:=1 to nscc do
    if pub[i] and (dp[i]>ans) then ans:=dp[i];
  writeln(ans);
end.
