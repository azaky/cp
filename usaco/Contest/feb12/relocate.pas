{
ID: a_zaky01
PROG: relocate
LANG: PASCAL
}

const
  maxv = 11111; //maximum number of vertices
  maxe = 55555; //maximum number of edges

var
  n,m,a,b,v1,v2,v,nheap,i,j,ans,distance,k:longint;
  visit,market:array[1..maxv] of boolean;
  w,ep1,ep2:array[1..maxe] of longint;
  deg,heap,pos:array[1..maxv] of longint;
  z,d:array[1..maxe*2] of longint;
  path:array[0..5,1..maxv] of longint;
  best:array[0..5,0..5] of longint;
  used:array[0..5] of boolean;
  mark:array[0..5] of longint;

function pop:longint;
  var
    i,p,c:longint;

  begin
    pop:=heap[1];
    i:=heap[nheap]; dec(nheap); p:=1;
    repeat
      c:=p*2;
      if (c<nheap) and (path[0][heap[c]]>path[0][heap[c+1]]) then inc(c);
      if (c>nheap) or (path[0][i]<=path[0][heap[c]]) then break;
      heap[p]:=heap[c]; pos[heap[p]]:=p; p:=c;
    until false;
    heap[p]:=i; pos[i]:=p;
  end;

procedure update(ps:longint);
  var
    i,p,c:longint;

  begin
    i:=heap[ps]; c:=ps;
    repeat
      p:=c div 2;
      if (p=0) or (path[0][i]>=path[0][heap[p]]) then break;
      heap[c]:=heap[p]; pos[heap[c]]:=c; c:=p;
    until false;
    heap[c]:=i; pos[i]:=c;
  end;

procedure walk(p,v,distance:longint);
  var
    i:longint;
  
  begin
    if p=k then
      begin
        if distance<best[j,v] then best[j,v]:=distance;
      end
    else for i:=1 to k do
      if not used[i] then
        begin
          used[i]:=true;
          walk(p+1,i,distance+path[v][mark[i]]);
          used[i]:=false;
        end;
  end;

Begin
  Assign(input, 'relocate.in'); Reset(input);
  Assign(output, 'relocate.out'); Rewrite(output);
    
  readln(n,m,k);
  
  for i:=1 to k do readln(mark[i]);
  fillchar(market,sizeof(market),false);
  for i:=1 to k do market[mark[i]]:=true;

  for i:=1 to m do
    begin
      readln(a,b,w[i]);
      inc(deg[a]); inc(deg[b]);
      ep1[i]:=a; ep2[i]:=b;
    end;

  for i:=2 to n+1 do deg[i]:=deg[i]+deg[i-1];
  for i:=1 to m do
    begin
      v1:=ep1[i]; v2:=ep2[i];
      z[deg[v1]]:=v2; d[deg[v1]]:=w[i]; dec(deg[v1]);
      z[deg[v2]]:=v1; d[deg[v2]]:=w[i]; dec(deg[v2]);
    end;

  for j:=1 to k do
    begin
    
      v1:=mark[j];

      heap[1]:=v1; pos[v1]:=1; nheap:=1;
      path[0][v1]:=0; 
      for i:=1 to n do
        if i<>v1 then
          begin
            inc(nheap); heap[nheap]:=i; pos[i]:=nheap;
            path[0][i]:=maxlongint;
          end;
      fillchar(visit,sizeof(visit),false);

      repeat
        a:=pop;
        if nheap=0 then break;
        visit[a]:=true;

        for i:=deg[a]+1 to deg[a+1] do
          begin
            v:=z[i];
            if visit[v] then continue;
            if path[0][v]>path[0][a]+d[i] then
              begin
                path[0][v]:=path[0][a]+d[i];
                update(pos[v]);
              end;
          end;
      until false;
  
      path[j]:=path[0];
  
    end;
  {
  write('':5);
  for i:=1 to n do write(i:5);
  writeln;
  for i:=1 to k do
    begin
      writeln;
      write(mark[i]:5);
      for j:=1 to n do write(path[i][j]:5);
      writeln;
    end;
  }
  fillchar(used,sizeof(used),false);
  for i:=1 to k do
    for j:=1 to k do
      best[i,j]:=maxlongint;
  for j:=1 to k do begin used[j]:=true; walk(1,j,0); used[j]:=false; end;
  {
  for i:=0 to k do write(mark[i]:10);
  writeln;
  for i:=1 to k do
    begin
      writeln;
      write(mark[i]:10);
      for j:=1 to k do write(best[i][j]:10);
      writeln;
    end;
  }
  ans:=maxlongint;
  for i:=1 to k-1 do
    for j:=i+1 to k do
      begin
        distance:=maxlongint;
        for a:=1 to n do
          if not market[a] then
            if path[i][a]+path[j][a]<distance then distance:=path[i][a]+path[j][a];
        distance:=distance+best[i,j];
        if distance<ans then ans:=distance;
      end;
  
  writeln(ans);

  Close(input); Close(output);
End.
