var
  n,m,i,mm,nS,nL,color,v,u:longint;
  cycle:boolean;
  ep1,ep2,deg,z,S,L,d,degback:array[0..211111] of longint;
  inL,visit:array[0..211111] of boolean;

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

function gcd(a,b:longint):longint;
  begin
    if a>b then exit(gcd(b,a))
      else if a=0 then exit(b)
        else exit(gcd(b mod a,a));
  end;

procedure dfs(v,depth:longint);
  var
    i:longint;
    
  begin
    //writeln('vertex #',v,' ',depth);
    //for i:=deg[v]+1 to deg[v+1] do write(z[i]:3);writeln;
    if visit[v] then
      begin
        color := gcd(color,abs(depth-d[v]));
        cycle := true;
        exit;
      end;
    visit[v]:=true; d[v]:=depth;
    for i:=deg[v]+1 to deg[v+1] do dfs(z[i],d[v]+1);
  end;

begin
  readln(n,m);
  for i:=1 to m do
    begin
      readln(ep1[i],ep2[i]);
      if ep1[i]=ep2[i] then
        begin
          writeln(1);halt;
        end;
    end;
  randomize;sort(1,m);mm:=0;
  for i:=1 to m do
    if not ((ep1[i]=ep1[i-1]) and (ep2[i]=ep2[i-1])) then
      begin
        inc(mm); ep1[mm]:=ep1[i]; ep2[mm]:=ep2[i];
      end;
  m:=mm;
  //for i:=1 to mm do writeln(ep1[i],'--',ep2[i]);
  for i:=1 to m do inc(deg[ep1[i]]);
  for i:=1 to n+1 do deg[i]:=deg[i]+deg[i-1];
  for i:=1 to m do
    begin
      z[deg[ep1[i]]]:=ep2[i];
      dec(deg[ep1[i]]);
    end;
//topological sorting
  for i:=1 to m do inc(degback[ep2[i]]);
  for i:=1 to n do
    if degback[i]=0 then
      begin
        inc(nS); s[nS]:=i;
      end;
  while nS>0 do
    begin
      v:=s[nS]; dec(nS);
      inc(nL); L[nL]:=v; inL[v]:=true;
      for i:=deg[v]+1 to deg[v+1] do
        begin
          u:=z[i]; dec(degback[u]);
          if degback[u]=0 then
            begin
              inc(nS); s[nS]:=u;
            end;
        end;
    end;
  for i:=1 to n do
    if not inL[i] then
      begin
        inc(nL); L[nL]:=i; cycle:=true;
      end;
  //writeln(cycle);
  //for i:=1 to n do write(l[i]:4);writeln;
//dfs
  for i:=1 to n do if not visit[L[i]] then dfs(L[i],0);
//in case there are no cycle
  if not cycle then color := n;
  writeln(color);
end.
