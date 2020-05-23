const
  maxv = 100005;

var
  n,i:longint;
  c,e1,e2,deg:array[0..maxv] of longint;
  h,z:array[0..2*maxv] of longint;

function ampas(v:longint):int64;
  var
    max,temp:int64;
    u,i:longint;
  
  begin
    visit[v]:=true;
    max:=0;
    for i:=deg[v]+1 to deg[v+1] do
      begin
        u:=h[i];
        if visit[u] then continue;
        temp:=d[i]+ampas(u);
        if temp>max then max:=temp;
      end;
    exit(max);
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(e1[i],e2[i],c[i]);
      inc(deg[e1[i]]); inc(deg[e2[i]]);
    end;
  for i:=1 to n+1 do deg[i]:=deg[i]+deg[i-1];
  for i:=1 to n do
    begin
      a:=e1[i]; b:=e2[i];
      h[deg[a]]:=b; h[deg[b]]:=a;
      d[deg[a]]:=c[i]; d[deg[b]]:=c[i];
      dec(deg[a]); dec(deg[b]);
    end;
  fillchar(visit,sizeof(visit),0);
  writeln(ampas(0));
end.

