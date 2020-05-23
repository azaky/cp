const maxn = 211111;

var
  n,k,i,a,b:longint;
  visit:array[0..maxn] of boolean;
  d,deg,ep1,ep2,z:array[0..maxn] of longint;

function longest(v:longint):longint;
  var
    i,ans:longint;
  
  procedure walk(w,depth:longint);
    var
      i:longint;
    
    begin
      if visit[w] then exit; d[w]:=depth; visit[w]:=true;
      for i:=deg[w]+1 to deg[w+1] do walk(z[i],depth+1);
    end;
  
  begin
    fillchar(visit,sizeof(visit),false);
    fillchar(d,sizeof(d),0);
    walk(v,0); ans:=v;
    for i:=1 to n do
      if d[i]>d[ans] then ans:=i;
    exit(ans);
  end;

begin
  readln(n,k);
  for i:=1 to n-1 do
    begin
      readln(ep1[i],ep2[i]);
      inc(deg[ep1[i]]); inc(deg[ep2[i]]);
    end;
  for i:=1 to n+1 do deg[i]:=deg[i-1]+deg[i];
  for i:=1 to n-1 do
    begin
      z[deg[ep1[i]]]:=ep2[i]; z[deg[ep2[i]]]:=ep1[i];
      dec(deg[ep1[i]]); dec(deg[ep2[i]]);
    end;
  //longest distance algorithm, only for k=1
  a := longest(1);
  b := longest(a);
  writeln(n,' ',k);
  writeln(2*n-d[b]-1);
end.
