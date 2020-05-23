{
ID: a_zaky01
PROG: butter
LANG: PASCAL
}

var
  i,j,k,n,p,c,a,b,d,tot,ans:longint;
  cow:array[1..500] of integer;
  nadj:array[1..800] of integer;
  adj:array[1..800,1..800] of integer;
  dis:array[1..800,1..800] of longint;
  fin,fout:text;

procedure fill(v:integer);
  var
    i,qtake,qsave:longint;
    temp:array[1..800] of longint;
    queue:array[1..5000] of integer;
    wait:array[1..800] of boolean;

  procedure dijkstra(q:longint);
    var
      i:integer;

    begin
      wait[queue[q]]:=false;
      for i:=1 to nadj[queue[q]] do
        if (temp[adj[queue[q],i]]<0) or (temp[adj[queue[q],i]]>temp[queue[q]]+dis[queue[q],adj[queue[q],i]]) then
          begin
            temp[adj[queue[q],i]]:=temp[queue[q]]+dis[queue[q],adj[queue[q],i]];
            if not wait[adj[queue[q],i]] then
              begin
                inc(qsave);
                wait[adj[queue[q],i]]:=true;
                queue[qsave]:=adj[queue[q],i];
              end;
          end;
      inc(qtake);
      if qtake<=qsave then dijkstra(qtake);
    end;

  begin
    fillchar(wait,sizeof(wait),false);
    fillchar(temp,sizeof(temp),255);
    temp[v]:=0;
    wait[v]:=true;
    queue[1]:=v;
    qtake:=1;
    qsave:=1;
    dijkstra(qtake);
    for i:=1 to p do dis[v,i]:=temp[i];
  end;

begin
  assign(fin,'butter.in');
  assign(fout,'butter.out');
  reset(fin);
  rewrite(fout);
  fillchar(dis,sizeof(dis),255);
  readln(fin,n,p,c);
  for i:=1 to n do readln(fin,cow[i]);
  for i:=1 to c do
    begin
      readln(fin,a,b,d);
      inc(nadj[a]);
      inc(nadj[b]);
      adj[a,nadj[a]]:=b;
      adj[b,nadj[b]]:=a;
      dis[a,b]:=d;
      dis[b,a]:=d;
    end;
  for i:=1 to p do dis[i,i]:=0;
  for i:=1 to n do fill(cow[i]);
  ans:=0;
  for i:=1 to p do
    begin
      tot:=0;
      for j:=1 to n do
         inc(tot,dis[cow[j],i]);
      if (ans=0) or (ans>tot) then ans:=tot;
    end;
  writeln(fout,ans);
  close(fin);
  close(fout);
end.
