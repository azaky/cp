{
ID: a_zaky01
PROG: stall4
LANG: PASCAL
}

uses
  math;

var
  n,m,i,j,a,b,cap0,totalflow,maxflow,maxloc,vi,pathcap,curnode,nextnode:longint;
  con:array[0..401,0..401] of boolean;
  deg,prevnode:array[0..401] of integer;
  adj:array[0..401,0..401] of integer;
  cap:array[0..401,0..401] of longint;
  flow:array[0..401] of longint;
  visit:array[0..401] of boolean;
  fin,fout:text;

label
  closefile;

begin
  assign(fin,'stall4.in');
  assign(fout,'stall4.out');
  reset(fin);
  rewrite(fout);

  readln(fin,n,m);
  if (n=0) or (m=0) then
    begin
      writeln(fout,0);
      goto closefile;
    end;
  deg[0]:=n;
  for i:=1 to n do adj[0,i]:=i;
  deg[n+m+1]:=m;
  for i:=n+1 to n+m do
    begin
      deg[i]:=1;
      adj[i,1]:=n+m+1;
      adj[n+m+1,i-n]:=i;
      cap[i,n+m+1]:=1;
    end;
  for i:=1 to n do
    begin
      read(fin,deg[i]);
      for j:=1 to deg[i] do
        begin
          read(fin,vi);
          inc(vi,n);
          inc(deg[vi]);
          adj[i,j]:=vi;
          adj[vi,deg[vi]]:=i;
          cap[i,vi]:=1;
        end;
      inc(deg[i]);
      adj[i,deg[i]]:=0;
      cap[0,i]:=1;
    end;
  m:=n+m+1;

  totalflow:=0;

  while true do
    begin
      fillchar(prevnode,sizeof(prevnode),0);
      fillchar(flow,sizeof(flow),0);
      fillchar(visit,sizeof(visit),false);
      flow[0]:=maxlongint;

      while true do
        begin
          maxflow:=0;
          maxloc:=-1;
          for i:=0 to m do
            if (flow[i]>maxflow) and not visit[i] then
              begin
                maxflow:=flow[i];
                maxloc:=i;
              end;
          if (maxloc<0) or (maxloc=m) then break;
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

      if maxloc<0 then break;

      pathcap:=flow[m];
      inc(totalflow,pathcap);
      curnode:=m;
      while curnode<>0 do
        begin
          nextnode:=prevnode[curnode];
          dec(cap[nextnode,curnode],pathcap);
          inc(cap[curnode,nextnode],pathcap);
          curnode:=nextnode;
        end;
    end;

  writeln(fout,totalflow);

  closefile:
  close(fin);
  close(fout);
end.
