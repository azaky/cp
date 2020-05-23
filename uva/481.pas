var
  n,i,ans,x,v:longint;
  a,idx,pos,last,RMQ,iRMQ,l,r,prev,seq:array[0..1 shl 18] of longint;

procedure build(ll,rr,v:longint);
  begin
    l[v] := ll; r[v] := rr;
    if ll=rr then exit;
    build(ll,(ll+rr) div 2,2*v); build((ll+rr+2) div 2,rr,2*v+1);
  end;

function Get(ll,rr,v:longint):longint;
  var
    x,y:longint;
  
  begin
    if (r[v]<ll) or (rr<l[v]) then exit(0);
    if (ll<=l[v]) and (r[v]<=rr) then exit(iRMQ[v]);
    x := Get(ll,rr,2*v); y := Get(ll,rr,2*v+1);
    if RMQ[x]>RMQ[y] then exit(x)
      else if RMQ[x]<RMQ[y] then exit(y);
    if idx[x]<idx[y] then exit(y) else exit(x);
  end;

procedure Update(x,v:longint);
  begin
    if (r[v]<x) or (x<l[v]) then exit;
    if (l[v]=r[v]) then
      begin
        iRMQ[v] := x;
        exit;
      end;
    Update(x,2*v); Update(x,2*v+1);
    if RMQ[iRMQ[2*v]]>RMQ[iRMQ[2*v+1]] then iRMQ[v]:=iRMQ[2*v]
      else if RMQ[iRMQ[2*v]]<RMQ[iRMQ[2*v+1]] then iRMQ[v]:=iRMQ[2*v+1]
        else if idx[iRMQ[2*v]]<idx[iRMQ[2*v+1]] then iRMQ[v]:=iRMQ[2*v+1]
          else iRMQ[v]:=iRMQ[2*v];
  end;

procedure sort(l,r:longint);
  var
    i,j,p,temp,mida,midi:longint;
  
  begin
    i:=l; j:=r; p:=random(r-l+1)+l; mida := a[p]; midi := idx[p];
    repeat
      while (a[i]<mida) or ((a[i]=mida) and (idx[i]<midi)) do inc(i);
      while (a[j]>mida) or ((a[j]=mida) and (idx[j]>midi)) do dec(j);
      if i>j then break;
      temp := a[i]; a[i]:=a[j]; a[j]:=temp;
      temp := idx[i]; idx[i]:=idx[j]; idx[j]:=temp;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  while not eof do begin inc(n); readln(a[n]); end;
  if n=0 then begin writeln(0); writeln('-'); halt; end;
  for i:=1 to n do idx[i] := i;
  randomize; sort(1,n);
  for i:=1 to n do pos[idx[i]] := i;
  last[1] := 1;
  for i:=2 to n do
    if a[i]=a[i-1] then last[i]:=last[i-1] else last[i]:=i;
  build(1,n,1);
  //for i:=1 to n do write(a[i]:5);writeln;
  //for i:=1 to n do write(idx[i]:5);writeln;
  for i:=1 to n do
    begin
      //writeln('analyzing node #',i,' at position ',pos[i]);
      //writeln('getting RMQ from 1 to ',last[pos[i]]-1);
      if last[pos[i]]=1 then x:=0
        else x := Get(1,last[pos[i]]-1,1);
      //writeln(x);
      RMQ[pos[i]] := RMQ[x]+1; prev[pos[i]] := x;
      Update(pos[i],1);
      //for v:=1 to n do write(RMQ[v]:5);writeln;
    end;
  ans := 0;
  for i:=1 to n do
    if (RMQ[i]>RMQ[ans]) or ((RMQ[i]=RMQ[ans]) and (idx[i]>idx[ans])) then ans := i;
  writeln(RMQ[ans]);writeln('-');
  v := ans;
  for i:=RMQ[ans] downto 1 do
    begin
      seq[i] := a[v]; v := prev[v];
    end;
  for i:=1 to RMQ[ans] do writeln(seq[i]);
end.
