{
ID: a_zaky01
PROG: telecow
LANG: PASCAL
}

uses
  math;

const
  maxn=200;

type
  capacity = array[1..maxn,1..maxn] of longint;

var
  n,m,i,a,b,c1,c2,curflow,tempflow,ans:longint;
  cut:array[1..maxn] of integer;
  deg:array[1..maxn] of integer;
  adj:array[1..maxn,1..maxn] of integer;
  cap:capacity;

function totalflow(const n,v1,v2:integer; cap:capacity):longint;
  var
    maxflow,maxloc,i,v,pathcap,curnode,nextnode:longint;
    prevnode:array[1..maxn] of integer;
    flow:array[1..maxn] of longint;
    visit:array[1..maxn] of boolean;
  
  begin
    totalflow:=0;

    while true do
      begin
        fillchar(prevnode,sizeof(prevnode),0);
        fillchar(flow,sizeof(flow),0);
        fillchar(visit,sizeof(visit),false);
        flow[v1]:=maxlongint;

        while true do
          begin
            maxflow:=0;
            maxloc:=0;
            for i:=1 to n do
              if (flow[i]>maxflow) and not visit[i] then
                begin
                  maxflow:=flow[i];
                  maxloc:=i;
                end;
            if (maxloc=0) or (maxloc=v2) then break;
            visit[maxloc]:=true;
            for i:=1 to deg[maxloc] do
              begin
                v:=adj[maxloc,i];
                if flow[v]<min(maxflow,cap[maxloc,v]) then
                  begin
                    prevnode[v]:=maxloc;
                    flow[v]:=min(maxflow,cap[maxloc,v]);
                  end;
              end;
          end;

        if maxloc=0 then break;

        pathcap:=flow[v2];
        inc(totalflow,pathcap);
        curnode:=v2;
        while curnode<>v1 do
          begin
            nextnode:=prevnode[curnode];
            dec(cap[nextnode,curnode],pathcap);
            inc(cap[curnode,nextnode],pathcap);
            curnode:=nextnode;
          end;
      end;
    
  end;

begin

  assign(input,'telecow.in');
  assign(output,'telecow.out');
  reset(input);
  rewrite(output);

  fillchar(cap,sizeof(cap),0);
  fillchar(deg,sizeof(deg),0);
  
  readln(n,m,c1,c2);
  
  for i:=1 to n do
    begin
      inc(deg[i]); adj[i,deg[i]]:=i+n;
      inc(deg[i+n]); adj[i+n,deg[i+n]]:=i;
      if (i=c1) or (i=c2) then cap[i,i+n]:=maxlongint
        else cap[i,i+n]:=1;
    end;
  
  for i:=1 to m do
    begin
      readln(a,b);
      cap[a+n,b]:=maxlongint;
      cap[b+n,a]:=maxlongint;
      inc(deg[a]); adj[a,deg[a]]:=b+n;
      inc(deg[b]); adj[b,deg[b]]:=a+n;
      inc(deg[a+n]); adj[a+n,deg[a+n]]:=b;
      inc(deg[b+n]); adj[b+n,deg[b+n]]:=a;
    end;

  curflow:=totalflow(2*n,c1,c2+n,cap);
  writeln(curflow);
  
  for i:=1 to n do
    if (i<>c1) and (i<>c2) then
      begin
        cap[i,i+n]:=0;
        tempflow:=totalflow(2*n,c1,c2+n,cap);
        if tempflow+1=curflow then
          begin
            inc(ans);
            cut[ans]:=i;
            curflow:=tempflow;
          end
        else inc(cap[i,i+n]);
        if curflow=0 then break;
      end;
  
  for i:=1 to ans-1 do write(cut[i],' ');
  writeln(cut[ans]);

  close(input);
  close(output);

end.

