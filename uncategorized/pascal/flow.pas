uses
  math;

const
  maxn=200;

type
  capacity = array[1..maxn,1..maxn] of longint;

var
  n,m,v1,v2,i,a,b,cap0:longint;
  deg:array[1..maxn] of integer;
  adj:array[1..maxn,1..maxn] of integer;
  cap:capacity;

function totalflow(n,v1,v2:integer; cap:capacity):longint;
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
  
  fillchar(cap,sizeof(cap),0);
  fillchar(deg,sizeof(deg),0);
  
  //the number of vertices and edges, source and sink node
  readln(n,m,v1,v2);
  
  //read the informations about edges
  for i:=1 to m do
    begin
      readln(a,b,cap0);
      inc(deg[a]); adj[a,deg[a]]:=b;
      inc(deg[b]); adj[b,deg[b]]:=a;
      inc(cap[a,b],cap0);
    end;

  writeln(totalflow(n,v1,v2,cap));

end.

