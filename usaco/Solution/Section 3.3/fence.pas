{
ID: a_zaky01
PROG: fence
LANG: PASCAL
}

var
  f,a,b,min,i,size:integer;
  deg,deg0:array[1..500] of integer;
  adj,degn:array[1..500,1..500] of integer;
  con:array[1..500,1..500] of boolean;
  circuit:array[1..1025] of integer;
  fin,fout:text;

procedure find(node:integer);
  var
    i,min:integer;

  begin
    while deg0[node]>0 do
      begin
        min:=-1;
        for i:=1 to deg[node] do
          if con[node,adj[node][i]] then
            if (min<0) or (min>adj[node][i]) then min:=adj[node][i];
        dec(deg0[node]);
        dec(deg0[min]);
        dec(degn[node][min]);
        dec(degn[min][node]);
        if degn[min][node]=0 then
          begin
            con[node,min]:=false;
            con[min,node]:=false;
          end;
        find(min);
      end;
    inc(size);
    circuit[size]:=node;
  end;

begin
  assign(fin,'fence.in');
  assign(fout,'fence.out');
  reset(fin);
  rewrite(fout);
  readln(fin,f);
  for i:=1 to f do
    begin
      readln(fin,a,b);
      inc(deg[a]);
      inc(deg[b]);
      inc(degn[a][b]);
      inc(degn[b][a]);
      adj[a][deg[a]]:=b;
      adj[b][deg[b]]:=a;
      con[a,b]:=true;
      con[b,a]:=true;
    end;
  min:=-1;
  for i:=1 to 500 do deg0[i]:=deg[i];
  for i:=1 to 500 do
    begin
      if min<0 then
        if deg[i]>0 then min:=i;
      if deg[i] mod 2=1 then
        begin
          min:=i;
          break;
        end;
    end;
  size:=0;
  find(min);
  for i:=size downto 1 do writeln(fout,circuit[i]);
  close(fin);
  close(fout);
end.
