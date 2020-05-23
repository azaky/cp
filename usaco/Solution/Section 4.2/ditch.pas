{
ID: a_zaky01
PROG: ditch
LANG: PASCAL
}

uses
  math;

var
  n,m,i,a,b,cap0,totalflow,maxflow,maxloc,vi,pathcap,curnode,nextnode:longint;
  con:array[1..200,1..200] of boolean;
  deg,prevnode:array[1..200] of integer;
  adj:array[1..200,1..200] of integer;
  cap:array[1..200,1..200] of longint;
  flow:array[1..200] of longint;
  visit:array[1..200] of boolean;
  fin,fout:text;

begin
  assign(fin,'ditch.in');
  assign(fout,'ditch.out');
  reset(fin);
  rewrite(fout);

  readln(fin,n,m);
  for i:=1 to n do
    begin
      readln(fin,a,b,cap0);
      if not con[a,b] then
        begin
          inc(deg[a]);
          inc(deg[b]);
          adj[a,deg[a]]:=b;
          adj[b,deg[b]]:=a;
        end;
      con[a,b]:=true;
      con[b,a]:=true;
      inc(cap[a,b],cap0);
    end;

  totalflow:=0;

  while true do
    begin
      fillchar(prevnode,sizeof(prevnode),0);
      fillchar(flow,sizeof(flow),0);
      fillchar(visit,sizeof(visit),false);
      flow[1]:=maxlongint;

      while true do
        begin
          maxflow:=0;
          maxloc:=0;
          for i:=1 to m do
            if (flow[i]>maxflow) and not visit[i] then
              begin
                maxflow:=flow[i];
                maxloc:=i;
              end;
          if (maxloc=0) or (maxloc=m) then break;
          visit[maxloc]:=true;
          for i:=1 to deg[maxloc] do
            begin
              vi:=adj[maxloc,i];
              if flow[vi]<min(maxflow,cap[maxloc,vi]) then
                begin
                  prevnode[vi]:=maxloc;
                  flow[vi]:=min(maxflow,cap[maxloc,vi]);
                end;
            end;
        end;

      if maxloc=0 then break;

      pathcap:=flow[m];
      inc(totalflow,pathcap);
      curnode:=m;
      while curnode<>1 do
        begin
          nextnode:=prevnode[curnode];
          dec(cap[nextnode,curnode],pathcap);
          inc(cap[curnode,nextnode],pathcap);
          curnode:=nextnode;
        end;
    end;

  writeln(fout,totalflow);

  close(fin);
  close(fout);
end.
