{
ID: a_zaky01
PROG: milk6
LANG: PASCAL
}

uses
  math;

type
  arr=array[1..32,1..32] of longint;
  edg=record
         a,b,cap,ind:longint;
       end;

var
  n,m,i,a0,b0,cap0,flow,tempflow,count:longint;
  con:array[1..32,1..32] of boolean;
  deg:array[1..32] of integer;
  cap,adj:arr;
  edge:array[1..1000] of edg;
  used:array[1..1000] of boolean;
  fin,fout:text;

function totalflow(cap:arr):longint;
  var
    i,maxflow,maxloc,pathcap,vi,curnode,nextnode:longint;
    flow,prevnode:array[1..32] of longint;
    visit:array[1..32] of boolean;

  begin
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
            for i:=1 to n do
              if (flow[i]>maxflow) and not visit[i] then
                begin
                  maxflow:=flow[i];
                  maxloc:=i;
                end;
            if (maxloc=0) or (maxloc=n) then break;
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
        pathcap:=flow[n];
        inc(totalflow,pathcap);
        curnode:=n;
        while curnode<>1 do
          begin
            nextnode:=prevnode[curnode];
            dec(cap[nextnode,curnode],pathcap);
            inc(cap[curnode,nextnode],pathcap);
            curnode:=nextnode;
          end;
      end;
    exit(totalflow);
  end;

procedure sort(l,r:longint);
  var
    i,j:longint;
    temp,mid:edg;

  begin
    i:=l;
    j:=r;
    mid:=edge[(l+r) div 2];
    repeat
      while (edge[i].cap>mid.cap) or ((edge[i].cap=mid.cap) and (edge[i].ind<mid.ind)) do inc(i);
      while (edge[j].cap<mid.cap) or ((edge[j].cap=mid.cap) and (edge[j].ind>mid.ind)) do dec(j);
      if i<=j then
        begin
          temp:=edge[i];
          edge[i]:=edge[j];
          edge[j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  assign(fin,'milk6.in');
  assign(fout,'milk6.out');
  reset(fin);
  rewrite(fout);

  readln(fin,n,m);
  for i:=1 to m do
    begin
      readln(fin,a0,b0,cap0);
      if not con[a0,b0] then
        begin
          inc(deg[a0]);
          inc(deg[b0]);
          adj[a0,deg[a0]]:=b0;
          adj[b0,deg[b0]]:=a0;
        end;
      con[a0,b0]:=true;
      con[b0,a0]:=true;
      inc(cap[a0,b0],cap0);
      with edge[i] do
        begin
          a:=a0;
          b:=b0;
          cap:=cap0;
          ind:=i;
        end;
    end;

  flow:=totalflow(cap);
  write(fout,flow,' ');
  sort(1,m);
  count:=0;

  for i:=1 to m do
    begin
      dec(cap[edge[i].a,edge[i].b],edge[i].cap);
      tempflow:=totalflow(cap);
      if tempflow+edge[i].cap=flow then
        begin
          inc(count);
          used[edge[i].ind]:=true;
          flow:=tempflow;
        end
      else inc(cap[edge[i].a,edge[i].b],edge[i].cap);
    end;

  writeln(fout,count);
  for i:=1 to m do
    if used[i] then writeln(fout,i);

  close(fin);
  close(fout);
end.
